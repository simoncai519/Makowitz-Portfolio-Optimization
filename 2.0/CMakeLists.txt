cmake_minimum_required(VERSION 3.16)
project(2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(util)

add_executable(2_0
        util/csv.cpp util/csv.h
        util/Matrix.cpp util/Matrix.h
        util/read_data.cpp util/read_data.h
        util/util.h
        basic_function.cpp basic_function.h
        backtest_class.cpp backtest_class.h
        main.cpp)
