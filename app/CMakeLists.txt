cmake_minimum_required (VERSION 2.8.11)

add_compile_options(-std=c++11)

aux_source_directory(src SOURCES)
add_executable (app ${SOURCES})

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
        ${GLRENDER_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        ${GLUT_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
)

target_link_libraries(app LINK_PUBLIC
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${GLRENDER_LIBRARIES}
)

if(WIN32)
    file(COPY libs/freeglut/bin/freeglut.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY libs/glew/lib/glew32.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
