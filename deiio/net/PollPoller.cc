// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/net/PollPoller.h>

#include <deiio/net/Channel.h>

namespace deiio {
namespace net {

PollPoller::~PollPoller() {
}

void PollPoller::poll(int timeoutMs, ChannelLists* activeChannels) {
  int numEvents = ::poll(&*pollfds_.begin(), pollfds_.size(), timeoutMs);

  for (PollFdList::iterator pfd = pollfds_.begin();
       pfd != pollfds_.end() && numEvents > 0;
       ++pfd) {
    if (pfd->revents > 0) {
      --numEvents;
      Channel* channel = channels_[pfd->fd];
      assert(channel->fd() == pfd->fd);
      channel->set_revents(pfd->revents);
      activeChannels->push_back(channel);
    }
  }
}

}  // namespace net
}  // namespace deiio

