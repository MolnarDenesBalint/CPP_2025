cmake_minimum_required(VERSION 4.0)
project(GameExamSampleGH)

set(CMAKE_CXX_STANDARD 26)

add_executable(GameExamSampleGH main.cpp
        game.cpp
        game.h
        user.cpp
        user.h)
