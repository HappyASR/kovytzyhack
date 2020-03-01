# kovytzyhack
Patch For kovytzy Platform

## Dependency:
- Python 2.7
https://www.python.org/ftp/python/2.7.12/python-2.7.12.msi

- cmake
https://cmake.org/download/

- Prebuilt GNU toolchain for m68k-elf
http://sysprogs.com/files/gnutoolchains/m68k-elf/m68k-elf-gcc4.8.0.exe


## How to build:
- git clone https://gitee.com/hackrom/kovytzyhack.git
- cd pgmhack
- mkdir build
- cd build
- cmake .. -DCMAKE_TOOLCHAIN_FILE=../pgm.cmake -G"Unix Makefiles"
- make -j8