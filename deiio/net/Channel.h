// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_NET_CHANNEL_H_
#define DEIIO_NET_CHANNEL_H_

#include <deiio/base/NonCopyable.h>
#include <deiio/net/Socket.h>

namespace deiio {
namespace net {

class EventLoop;

class Channel : public NonCopyable {
 public:
  Channel(EventLoop* loop, Socket sock);
  ~Channel();

  void handle(int revents);

  EventLoop* getloop() { return loop_; }

 private:
  EventLoop*  loop_;
  Socket      sock_;
  int         events_;
};

}  // namespace net
}  // namespace deiio

#endif  // DEIIO_NET_CHANNEL_H_

