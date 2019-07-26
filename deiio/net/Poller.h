// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_NET_POLLER_H_
#define DEIIO_NET_POLLER_H_

#include <deiio/base/NonCopyable.h>

namespace deiio {
namespace net {

/**
 * Base class for IO Multiplexing
 */
class Poller : public NonCopyable {
 public:
  virtual ~Poller();

  virtual void poll(int timeoutMs) = 0;

  static Poller* newDefaultPoller();
};

}  // namespace net
}  // namespace deiio

#endif  // DEIIO_NET_POLLER_H_

