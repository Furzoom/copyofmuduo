// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/net/Poller.h>
#include <deiio/net/PollPoller.h>

namespace deiio {
namespace net {

Poller* Poller::newDefaultPoller() {
  return new PollPoller;
}

}  // namespace net
}  // namespace deiio

