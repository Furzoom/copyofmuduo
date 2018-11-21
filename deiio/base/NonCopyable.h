// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_BASE_NON_COPYABLE_H_
#define DEIIO_BASE_NON_COPYABLE_H_

namespace deiio {

/**
 * NonCopyable base class.
 */
class NonCopyable {
 public:
  NonCopyable() = default;
  NonCopyable(const NonCopyable&) = delete;
  NonCopyable& operator=(const NonCopyable&) = delete;
};

}  // namesapce deiio

#endif  // DEIIO_BASE_NON_COPYABLE_H_

