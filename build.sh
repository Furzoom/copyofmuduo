#!/bin/sh

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-./build}
if [ ! -f $BUILD_DIR ]; then
  mkdir $BUILD_DIR
fi
cd $BUILD_DIR
cmake $SOURCE_DIR
make
