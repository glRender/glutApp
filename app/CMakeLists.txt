cmake_minimum_required (VERSION 2.8.11)

add_compile_options(-std=c++11 -ldl)

aux_source_directory(src SOURCES)
add_executable (App ${SOURCES})

find_package(GLUT REQUIRED)

include_directories(
    ${GLUT_INCLUDE_DIR}
    ${GLRENDER_INCLUDE_DIR}
)

target_link_libraries(App LINK_PUBLIC
    ${GLUT_LIBRARIES}
    ${GLRENDER_LIBRARIES}
)


file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
