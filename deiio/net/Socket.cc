// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/net/Socket.h>

#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>

namespace deiio {
namespace net {

void Socket::setTcpNoDelay(bool on) {
  int optval = on ? 1 : 0;
  ::setsockopt(sockfd_, IPPROTO_TCP, TCP_NODELAY,
               &optval, sizeof optval);
}

}  // namespace net
}  // namespace deiio

