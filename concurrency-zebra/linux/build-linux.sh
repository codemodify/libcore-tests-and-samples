#!/bin/sh
rm -rf build && mkdir build

export libCoreDef=libCoreLinux
cmake -S . -B build
cd build
make
./concurrency-zebra