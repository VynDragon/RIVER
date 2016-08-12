cmake_minimum_required(VERSION 3.6)
project(RIVER)
include_directories(./include)
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")
set(SOURCES ./src/main.c
./src/cpu.c
./src/emulate.c
./src/ISA.c
)
add_executable(RIVER ${SOURCES})
