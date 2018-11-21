// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/net/Timer.h>

namespace deiio {
namespace net {

void Timer::restart(UtcTime now) {
  if (repeat_) {
    expiration_ = addTime(now, interval_);
  } else {
    expiration_ = UtcTime::invalid();
  }
}

}  // namespace net
}  // namespace deiio

