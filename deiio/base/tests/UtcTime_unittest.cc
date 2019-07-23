// Copyright 2018 furzoom.com. All Rights Reserved.
// Author: mn@furzoom.com

#include <deiio/base/UtcTime.h>

#include <stdio.h>

using deiio::UtcTime;

void passByConstReference(const UtcTime& x) {
  printf("%s\n", x.toString().c_str());
}

void passByValue(UtcTime x) {
  printf("%s\n", x.toString().c_str());
}

int main() {
  UtcTime now(UtcTime::now());
  printf("%s\n", now.toString().c_str());
  passByValue(now);
  passByConstReference(now);

  return 0;
}

