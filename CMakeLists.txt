cmake_minimum_required(VERSION 3.16)

project(crosslibc LANGUAGES C)

file(GLOB CROSSLIBC_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/printf/*.c
)

add_library(crosslibc STATIC ${CROSSLIBC_SRCS})
include_directories(SYSTEM
    ${CMAKE_CURRENT_SOURCE_DIR}
)
