// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/base/Thread.h>

#include <stdio.h>
#include <unistd.h>

using deiio::Thread;

void worker() {
  printf("worker tid: %d\n", deiio::CurrentThread::tid());
  for (int i = 0; i < 3; ++i) {
    printf("worker...\n");
    usleep(1000);
  }
}

int main() {
  Thread thread(worker);
  thread.start();

  printf("main tid: %d\n", deiio::CurrentThread::tid());
  thread.join();

  return 0;
}

