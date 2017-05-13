cmake_minimum_required(VERSION 3.6)
project(Projeto)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Libraries/Exames.h Libraries/Menus.c Libraries/Menus.h Libraries/Disciplinas.c Libraries/Disciplinas.h Libraries/Estruturas.h Libraries/Alunos.c Libraries/Alunos.h)
add_executable(Projeto ${SOURCE_FILES})