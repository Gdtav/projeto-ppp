cmake_minimum_required(VERSION 3.6)
project(Projeto)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Libraries/Exames.h)
add_executable(Projeto ${SOURCE_FILES})