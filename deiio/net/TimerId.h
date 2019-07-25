// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_NET_TIMERID_H_
#define DEIIO_NET_TIMERID_H_

namespace deiio {
namespace net {

class Timer;

class TimerId {
 public:
  explicit TimerId(Timer* timer) : value_(timer) {}

 private:
  Timer* value_;
};

}  // namespace net
}  // namespace deiio

#endif  // DEIIO_NET_TIMERID_H_

