cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

project(ProcessMonitor)

set (
    INFOPARSER_LIB
    lib/InfoParser.cpp
    lib/InfoParser.hpp
)

add_library(InfoParser STATIC ${INFOPARSER_LIB})
