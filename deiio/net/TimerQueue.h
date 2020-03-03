// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_NET_TIMER_QUEUE_H_
#define DEIIO_NET_TIMER_QUEUE_H_

#include <functional>
#include <list>

#include <deiio/base/NonCopyable.h>
#include <deiio/base/UtcTime.h>
#include <deiio/net/Channel.h>

namespace deiio {
namespace net {

class EventLoop;
class Timer;
class TimerId;

class TimerQueue : public NonCopyable {
 public:
  typedef std::function<void()> TimerCallback;

  TimerQueue(EventLoop* loop);
  ~TimerQueue();

  /**
   * Schedules the callback to be run at given time,
   * repeats if $c interval > 0.0.
   */
  TimerId schedule(const TimerCallback& cb, UtcTime at, double interval);

  void cancel(TimerId timerId);

 private:
  void timeout();

  typedef std::list<Timer*> Timers;

  EventLoop* loop_;
  int timerfd_;
  Channel timerfdChannel_;
  Timers timers_;
};

}  // namespace net
}  // namespace deiio

#endif  // DEIIO_NET_TIMER_QUEUE_H_

