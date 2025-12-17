cmake_minimum_required(VERSION 3.10)
project(MSH_M8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MSH_M8)

target_include_directories(MSH_M8
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external
        ${CMAKE_CURRENT_SOURCE_DIR}/external/commands
    
    PRIVATE
        src
        src/Helpers
        src/MenuActions
)

target_sources(MSH_M8
    PRIVATE
        src/MSH_M8.cpp
    
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MSH_M8.h
)

include(CTest)
enable_testing()

