cmake_minimum_required(VERSION 4.0)
project(C2025ExamSample)

set(CMAKE_CXX_STANDARD 26)

add_executable(C2025ExamSample main.cpp
        Konyv.cpp
        Konyv.h
        KonyvtariStatisztika.cpp
        KonyvtariStatisztika.h)
