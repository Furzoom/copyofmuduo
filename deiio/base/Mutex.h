// Copyright 2019 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#ifndef DEIIO_BASE_MUTEX_H_
#define DEIIO_BASE_NUTEX_H_

#include <pthread.h>

#include <deiio/base/NonCopyable.h>

namespace deiio {

class MutexLock : public NonCopyable {
 public:
  MutexLock() {
    pthread_mutex_init(&mutex_, NULL);
  }

  ~MutexLock() {
    pthread_mutex_destroy(&mutex);
  }

  void lock() {
    pthread_mutex_lock(&mutex);
  }

  void unlock() {
    pthread_mutex_unlock(&mutex);
  }

  pthread_mutex_t* getPthreadMutex() { // non-const
    return &mutex_;
  }

 private:
  pthread_mutex_t mutex_;
};

class MutexLockGuard : public NonCopyable {
 public:
  explicit MutexLockGuard(MutexLock& mutex) : mutex_(mutex) {
    mutex_.lock();
  }

  ~MutexLockGuard() {
    mutex_.unlock();
  }

 private:
  MutexLock& mutex_;
};

}  // namespace deiio

#define MutexLockGuard(x) error

#endif  // DEIIO_BASE_NUTEX_H_

