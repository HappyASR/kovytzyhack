cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../pgm.cmake -G"Unix Makefiles"
make -j8