cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)

project(ProcessMonitor)

add_executable(ProcessMonitor)

target_sources(ProcessMonitor
    PRIVATE
        main.cpp
        InfoParser.cpp
        InfoParser.hpp
)
