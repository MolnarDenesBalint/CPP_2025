cmake_minimum_required(VERSION 4.0)
project(InfExamSample2021)

set(CMAKE_CXX_STANDARD 26)

add_executable(InfExamSample2021 main.cpp
        book.cpp
        book.h
        library.cpp
        library.h)
