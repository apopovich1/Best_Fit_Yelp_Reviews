cmake_minimum_required(VERSION 3.27)
project(Best_Fit_Yelp_Reviews1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Best_Fit_Yelp_Reviews1 src/main.cpp
        src/Parsing.h
        src/Parsing.cpp
        src/Sorter.cpp)
