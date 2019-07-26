// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/net/EventLoop.h>
#include <deiio/net/Poller.h>
#include <deiio/net/TimerQueue.h>

namespace deiio {
namespace net {

EventLoop::EventLoop()
  : poller_(Poller::newDefaultPoller()),
    timerQueue_(new TimerQueue),
    quit_(false) {
  init();
}

EventLoop::~EventLoop() {
}

void EventLoop::loop() {
  while (!quit_) {
    poller_->poll(1000);
  }
}

void EventLoop::init() {
}

void EventLoop::quit() {
  quit_ = true;
}

TimerId EventLoop::runAt(const UtcTime& time, const TimerCallback& cb) {
  return timerQueue_->schedule(cb, time, 0.0);
}

TimerId EventLoop::runAfter(double delay, const TimerCallback& cb) {
  UtcTime time(addTime(UtcTime::now(), delay));
  return runAt(time, cb);
}

TimerId EventLoop::runEvery(double interval, const TimerCallback& cb) {
  UtcTime time(addTime(UtcTime::now(), interval));
  return timerQueue_->schedule(cb, time, interval);
}

}  // namespace net
}  // namespace deiio

