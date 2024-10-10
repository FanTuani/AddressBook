cmake_minimum_required(VERSION 3.27)
project(AddressBook C)

set(CMAKE_C_STANDARD 17)

add_executable(AddressBook main.c
        displays.h
        displays.c
        operations.c
        operations.h
        fileInterations.c
        fileInterations.h
        constants.h)
