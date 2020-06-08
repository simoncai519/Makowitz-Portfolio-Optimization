cmake_minimum_required(VERSION 3.16)
project(Coursework)

set(CMAKE_CXX_STANDARD 14)

add_executable(1.0 main.cpp
        csv.h csv.cpp read_data.cpp read_data.h
        Matrix.h Matrix.cpp util.h
        A.h A.cpp
        B.h B.cpp
        C.h C.cpp)