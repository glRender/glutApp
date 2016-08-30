cmake_minimum_required (VERSION 2.8.11)
project (Project)

set (CMAKE_CXX_STANDARD 11)

if(WIN32)
    set(CMAKE_SH "C:/MinGW/msys/1.0/bin/sh.exe")
endif()

add_subdirectory (src/glRender)
add_subdirectory (src/app)