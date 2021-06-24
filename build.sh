#!/bin/bash
mkdir build 
cd build
cmake -DCMAKE_INSTALL_PREFIX=package ..

cmake --build . --config Release
ctest -C Release
cmake --build . --config Release --target install

cd ..