cmake_minimum_required(VERSION 3.6)
project(RIVER)
include_directories(./include)
set(SOURCES ./src/main.c \
)
add_executable(RIVER ${SOURCES})
