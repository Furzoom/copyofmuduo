// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_NET_TIMER_H_
#define DEIIO_NET_TIMER_H_

#include <functional>

#include <deiio/base/NonCopyable.h>
#include <deiio/base/UtcTime.h>

namespace deiio {
namespace net {

/**
 * Internal class for timer event.
 */
class Timer : public NonCopyable {
 public:
  typedef std::function<void()> TimerCallback;

  Timer(const TimerCallback& cb, UtcTime at, double interval)
    : cb_(cb),
      expiration_(at),
      interval_(interval),
      repeat_(interval > 0.0) { }

  void run() const {
    cb_();
  }

  UtcTime expiration() const { return expiration_; }

  bool repeat() const { return repeat_; }

  void restart(UtcTime now);

 private:
  const TimerCallback cb_;
  UtcTime expiration_;
  const double interval_;
  const bool repeat_;
};

}  // namespace net
}  // namespace deiio

#endif  // DEIIO_NET_TIMER_H_

