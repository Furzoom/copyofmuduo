// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/net/Timer.h>
#include <deiio/net/TimerId.h>
#include <deiio/net/TimerQueue.h>

namespace deiio {
namespace net {

TimerQueue::TimerQueue() {
}

TimerQueue::~TimerQueue() {
}

void TimerQueue::tick(UtcTime now) {
}

TimerId TimerQueue::schedule(const TimerCallback& cb,
                             UtcTime at,
                             double interval) {
  Timer* timer = new Timer(cb, at, interval);
  timers_.push_front(timer);
  return TimerId(timer);
}

}  // namespace net
}  // namespace deiio

