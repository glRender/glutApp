cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -pedantic")

aux_source_directory(src SOURCES)
add_executable (App ${SOURCES})


find_package(GLUT REQUIRED)

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/local/lib/cmake/FindglRender.cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /home/lizin_as/develop/c++/opengl/glRender/cmake/Modules/FindglRender.cmake)
message(STATUS ${CMAKE_MODULE_PATH})
find_package(glRender REQUIRED)

# set(GLRENDER_INCLUDE_DIR /opt/glRender_0.8.0/include/)
# set(GLRENDER_LIBRARIES /opt/glRender_0.8.0/lib/libglRender.so)

include_directories(
    ${GLUT_INCLUDE_DIR}
    # ${GLRENDER_INCLUDE_DIR}
    ${glRender_INCLUDE_DIRS}
)

target_link_libraries(App LINK_PUBLIC
    ${GLUT_LIBRARIES}
    # ${GLRENDER_LIBRARIES}
    ${glRender_LIBRARIES}
)


file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
