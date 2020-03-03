// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/base/Thread.h>

#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

namespace {

__thread pid_t t_tid = 0;

pid_t gettid() {
  return static_cast<pid_t>(::syscall(SYS_gettid));
}

void *startThread(void *cb) {
  auto* func = static_cast<deiio::Thread::ThreadFunc*>(cb);
  t_tid = gettid();
  (*func)();
  return nullptr;
}

}  // anonymous namespace

namespace deiio {

Thread::Thread(const ThreadFunc& func)
  : ptid_(0),
    func_(func) {
}

Thread::~Thread() {}

void Thread::start() {
  pthread_create(&ptid_, nullptr, &startThread, &func_);
}

void Thread::join() {
  pthread_join(ptid_, nullptr);
}

namespace CurrentThread {

pid_t tid() {
  if (t_tid == 0) {
    t_tid = gettid();
  }
  return t_tid;
}

}  // namespace CurrentThread
}  // namespace deiio

