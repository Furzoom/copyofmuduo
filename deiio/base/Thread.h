// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_BASE_THREAD_H_
#define DEIIO_BASE_THREAD_H_

#include <functional>

#include <pthread.h>

namespace deiio {

class Thread {
 public:
  typedef std::function<void ()> ThreadFunc;

  explicit Thread(const ThreadFunc&);
  ~Thread();

  void start();
  void join();

 private:
  pthread_t ptid_;
  ThreadFunc func_;
};

namespace CurrentThread {

pid_t tid();

}  // namespace CurrentTread
}  // namespace deiio

#endif  // DEIIO_BASE_THREAD_H_

