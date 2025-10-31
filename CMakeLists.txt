cmake_minimum_required(VERSION 3.16)

project(crosslibc LANGUAGES C)


option(CLIBC_NO_HEAP "Disable heap functionality" ON)
if (NOT CLIBC_NO_HEAP)
    option(CLIBC_NO_LL_HEAP "Disable low-level heap functionality" OFF)
else()
    set(CLIBC_NO_LL_HEAP ON)
endif()
option(CLIBC_NO_FLOAT "Disable floating point support" OFF)


file(GLOB CROSSLIBC_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/printf/*.c
)

add_library(crosslibc ${CROSSLIBC_SRCS})
target_include_directories(crosslibc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/STL
)


if(CLIBC_NO_HEAP)
    target_compile_definitions(crosslibc PUBLIC CLIBC_NO_HEAP)
endif()

if(CLIBC_NO_LL_HEAP)
    target_compile_definitions(crosslibc PUBLIC CLIBC_NO_LL_HEAP)
endif()

if(CLIBC_NO_FLOAT)
    target_compile_definitions(crosslibc PUBLIC CLIBC_NO_FLOAT)
endif()


message(STATUS "crosslibc Configuration:")
message(STATUS "  CLIBC_NO_HEAP: ${CLIBC_NO_HEAP}")
message(STATUS "  CLIBC_NO_LL_HEAP: ${CLIBC_NO_LL_HEAP}")
message(STATUS "  CLIBC_NO_FLOAT: ${CLIBC_NO_FLOAT}")
