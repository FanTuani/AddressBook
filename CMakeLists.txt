cmake_minimum_required(VERSION 3.24)
project(AddressBook C)

set(CMAKE_C_STANDARD 17)

add_executable(AddressBook sources/main.c
        headers/displays.h
        sources/displays.c
        sources/operations.c
        headers/operations.h
        sources/fileInteractions.c
        headers/fileInteractions.h
        headers/constants.h)
