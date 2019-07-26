// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/net/Channel.h>

namespace deiio {
namespace net {

Channel::Channel(EventLoop* loop, Socket sock)
  : loop_(loop),
    sock_(sock),
    events_(0) {
}

Channel::~Channel() {
}

}  // namespace net
}  // namespace deiio

