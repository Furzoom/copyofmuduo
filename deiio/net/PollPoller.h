// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_NET_POLLPOLLER_H_
#define DEIIO_NET_POLLPOLLER_H_

#include <deiio/net/Poller.h>

#include <poll.h>

#include <vector>

namespace deiio {
namespace net {

/**
 * IO Multiplexing with poll(2)
 */
class PollPoller : public Poller {
 public:
  virtual ~PollPoller();

  virtual void poll(int timeoutMs);

 private:
  typedef std::vector<struct pollfd> PollFdList;
  PollFdList pollfds_;
};

}  // namespace net
}  // namespace deiio

#endif  // DEIIO_NET_POLLPOLLER__H_

