// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_NET_POLLPOLLER_H_
#define DEIIO_NET_POLLPOLLER_H_

#include <poll.h>

#include <map>
#include <vector>

#include <deiio/net/Poller.h>

namespace deiio {
namespace net {

/**
 * IO Multiplexing with poll(2)
 */
class PollPoller : public Poller {
 public:
  virtual ~PollPoller();

  virtual void poll(int timeoutMs, ChannelList* activeChannels);

 private:
  typedef std::vector<struct pollfd> PollFdList;
  PollFdList pollfds_;
  std::map<int, Channel*> channels_;
};

}  // namespace net
}  // namespace deiio

#endif  // DEIIO_NET_POLLPOLLER__H_

