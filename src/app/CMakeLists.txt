cmake_minimum_required (VERSION 2.8.11)

set (CMAKE_CXX_STANDARD 11)

if(WIN32)
    set(CMAKE_SH "C:/MinGW/msys/1.0/bin/sh.exe")
endif()

aux_source_directory(src SOURCES)
add_executable (app src/main.cpp)

find_package(OpenGL REQUIRED)

if(WIN32)
        set(GLUT_glut_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/libs/freeglut/lib/libfreeglut.a )
        set(GLUT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/freeglut/include )

        set(GLEW_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/libs/glew/lib/glew32.dll )
        set(GLEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/glew/include )
endif()

find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLUT_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
)

target_link_libraries(
        app
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARIES}
        ${GLEW_LIBRARIES}
        glRender
)

if(WIN32)
    file(COPY libs/freeglut/bin/freeglut.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY libs/glew/lib/glew32.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
