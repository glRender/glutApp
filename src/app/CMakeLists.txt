set (CMAKE_CXX_STANDARD 11)

aux_source_directory(src SOURCES)
add_executable (main src/main.cpp)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(
        ${GLUT_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
)

target_link_libraries(
        main
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        glRender
)

if(WIN32)
    file(COPY libs/freeglut/bin/freeglut.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY libs/glew/lib/glew32.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
