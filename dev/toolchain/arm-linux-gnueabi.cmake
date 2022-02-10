set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(prefix arm-linux-gnueabi)
set(CMAKE_C_COMPILER ${prefix}-gcc)
set(CMAKE_CROSSCOMPILING_EMULATOR qemu-i386 -L /usr/${prefix})