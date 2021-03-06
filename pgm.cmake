# (c) 2016  XingXing(HappyASR#gmail.com)

include(CMakeForceCompiler)

# The Generic system name is used for embedded targets (targets without OS) in
# CMake
# set( CMAKE_SYSTEM_NAME          Generic )
set( CMAKE_SYSTEM_NAME          Linux )
set( CMAKE_SYSTEM_PROCESSOR     ARMV5 )

# Set a toolchain path. You only need to set this if the toolchain isn't in
# your system path. Don't forget a trailing path separator!
# set( TC_PATH "" )

# The toolchain prefix for all toolchain executables
set( CROSS_COMPILE m68k-linux-gnu- )

set( CMAKE_C_COMPILER ${TC_PATH}${CROSS_COMPILE}gcc )
set( CMAKE_CXX_COMPILER ${TC_PATH}${CROSS_COMPILE}g++ )
set( CMAKE_ASM_COMPILER ${TC_PATH}${CROSS_COMPILE}gcc )
set( CMAKE_OBJCOPY      ${TC_PATH}${CROSS_COMPILE}objcopy )

set( CMAKE_C_COMPILER_WORKS 1)

set( GAME_MAP "./game.map")
set( ROM_OFFSET "0x380000")
set( ROM_INPUT "ytzy_v201cn_d.rom")
set( ROM_OUTPUT "ytzy_v201cn_h.rom")

# Set the CMAKE C flags (which should also be used by the assembler!# -Werror
set( CMAKE_C_FLAGS "-m68000 -std=c99 -fomit-frame-pointer -O2 -Winline -Wall -Wa,--register-prefix-optional -I. -Isrc" )
set( CMAKE_EXE_LINKER_FLAGS "-nostdlib -Wl,-Map,${GAME_MAP},-T,../pgm.lds,--section-start,.rom=0x100000,--section-start,.ram=0x808000")
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "" )
set( CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "" )
set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}" CACHE STRING "" )
