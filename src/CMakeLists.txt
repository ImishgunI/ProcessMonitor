cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

project(ProcessMonitor)

set (
    SOURCES_LIB
    InfoParser.cpp
    InfoParser.hpp
)

add_library(ProcessMonitor STATIC ${SOURCES_LIB})
