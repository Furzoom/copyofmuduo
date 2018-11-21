// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_NET_SOCKET_H_
#define DEIIO_NET_SOCKET_H_

namespace deiio {
/**
 * TCP networking.
 */
namespace net {

/**
 * Wrapper of socket file descriptor.
 */
class Socket {
 public:
  explicit Socket(int sockfd) : sockfd_(sockfd) { }

  int fd() { return sockfd_; }

  /**
   * Enable/disable TCP_NODELAY (disable/enable Nagle's algorithm).
   */
  void setTcpNoDelay(bool on);

 private:
  int sockfd_;
};

}  // namespace net
}  // namespace deiio

#endif  // DEIIO_NET_SOCKET_H_

