// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/net/PollPoller.h>

namespace deiio {
namespace net {

PollPoller::~PollPoller() {
}

void PollPoller::poll(int timeoutMs) {
  // make a copy
  PollFdList pollfds(pollfds_);
  int numEvents = ::poll(&*pollfds.begin(), pollfds.size(), timeoutMs);

  for (PollFdList::iterator pfd = pollfds.begin();
       pfd != pollfds.end() && numEvents > 0;
       ++pfd) {
    if (pfd->revents > 0) {
      --numEvents;
      // do something
    }
  }
}

}  // namespace net
}  // namespace deiio

