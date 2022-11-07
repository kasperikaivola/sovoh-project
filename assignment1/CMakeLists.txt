cmake_minimum_required(VERSION 3.16)
project(Assignment1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Assignment1 as1.c logging.c logging.h)
add_executable(Assignment1-exec execmain.c morse.c morse.h logging.c logging.h)

target_compile_options(Assignment1 PRIVATE -Wall -pedantic -Wextra)
target_compile_options(Assignment1-exec PRIVATE -Wall -pedantic -Wextra)