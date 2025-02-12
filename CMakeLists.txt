cmake_minimum_required(VERSION 3.28)

project(console_game)

add_library(functions STATIC functions.c)

add_executable(console_game main.c)

target_link_libraries(console_game functions)