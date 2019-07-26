// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_NET_EVENTLOOP_H_
#define DEIIO_NET_EVENTLOOP_H_

#include <memory>
#include <functional>

#include <deiio/base/NonCopyable.h>
#include <deiio/base/UtcTime.h>
#include <deiio/net/TimerId.h>

namespace deiio {
namespace net {

class Channel;
class Poller;
class TimerQueue;

class EventLoop : public NonCopyable {
 public:
  typedef std::function<void()> TimerCallback;

  EventLoop();
  ~EventLoop();

  // Loops forever
  void loop();

  void quit();
  void wakeup();

  // timers
  TimerId runAt(const UtcTime& time, const TimerCallback& cb);
  TimerId runAfter(double delay, const TimerCallback& cb);
  TimerId runEvery(double interval, const TimerCallback& cb);
  void cancel(TimerId timerId);

  void addChannel(Channel* channel);
  void removeChannel(Channel* channel);

 private:
  void init();

  std::unique_ptr<Poller> poller_;
  std::unique_ptr<TimerQueue> timerQueue_;
  bool quit_;  // atomic
};

}  // namespace net
}  // namespace deiio

#endif  // DEIIO_NET_EVENTLOOP_H_

