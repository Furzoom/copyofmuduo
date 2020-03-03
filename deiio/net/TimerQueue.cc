// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/net/TimerQueue.h>

#include <deiio/net/EventLoop.h>
#include <deiio/net/Timer.h>
#include <deiio/net/TimerId.h>

namespace deiio {
namespace net {
namespace {

int createTimerfd() {
  int timerfd = ::timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK | TFD_CLOEXEC);
  if (timerfd < 0) {
    perror("Failed in timerfd_create");
    abort();
  }
  return timerfd;
}

}  // anonymous namespace

TimerQueue::TimerQueue(EventLoop* loop)
  : loop_(loop),
    timerfd_(createTimerfd()),
    timerfdChannel_(loop, timerfd),
    timers_() {
  timerfdChannel_.setReadCallback(std::bind(&TimerQueue::timeout, this));
}

TimerQueue::~TimerQueue() {
  ::close(timerfd_);
}

void TimerQueue::timeout() {
  timerfdChannel_.set_events(0);
  loop->updateChannel(&timerfdChannel_);
}

TimerId TimerQueue::schedule(const TimerCallback& cb,
                             UtcTime at,
                             double interval) {
  Timer* timer = new Timer(cb, at, interval);
  timers_.push_front(timer);
  timerfdChannel_.set_events(Channel::kReadEvent);
  loop_->updateChannel(&timerfdChannel_);
  return TimerId(timer);
}

}  // namespace net
}  // namespace deiio

