// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_NET_POLLER_H_
#define DEIIO_NET_POLLER_H_

#include <vector>

#include <deiio/base/NonCopyable.h>

namespace deiio {
namespace net {

class Channel;

/**
 * Base class for IO Multiplexing
 */
class Poller : public NonCopyable {
 public:
  typedef std::vector<Channel*> ChannelList;

  virtual ~Poller();

  virtual void poll(int timeoutMs, ChannelList* activeChannels) = 0;

  static Poller* newDefaultPoller();
};

}  // namespace net
}  // namespace deiio

#endif  // DEIIO_NET_POLLER_H_

