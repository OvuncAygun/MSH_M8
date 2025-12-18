cmake_minimum_required(VERSION 3.10)
project(MSH_M8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MSH_M8)

target_include_directories(MSH_M8
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/external
        ${CMAKE_CURRENT_SOURCE_DIR}/external/commands
        src
        src/Helpers
        src/MenuActions
)

target_sources(MSH_M8
    PRIVATE
        src/MSH_M8.cpp
        src/MSHMenuManager.cpp
        src/Helpers/InputHandler.cpp
        src/Helpers/MenuDisplayer.cpp
        src/MenuActions/GetHomeStatusAction.cpp
        src/MenuActions/AddDeviceAction.cpp
        src/MenuActions/RemoveDeviceAction.cpp
        src/MenuActions/PoweronDeviceAction.cpp
        src/MenuActions/PoweroffDeviceAction.cpp
        src/MenuActions/ChangeModeAction.cpp
        src/MenuActions/ChangeStateAction.cpp
        src/MenuActions/ManualAction.cpp
        src/MenuActions/AboutAction.cpp
        src/MenuActions/ShutdownAction.cpp
    
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MSH_M8.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/IMSHMenuManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MenuAction.h
)

include(CTest)
enable_testing()

