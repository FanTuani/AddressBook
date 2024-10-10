cmake_minimum_required(VERSION 3.27)
project(AddressBook C)

set(CMAKE_C_STANDARD 17)

add_executable(AddressBook sources/main.c
        headers/displays.h
        sources/displays.c
        sources/operations.c
        headers/operations.h
        sources/fileInterations.c
        headers/fileInterations.h
        headers/constants.h)
