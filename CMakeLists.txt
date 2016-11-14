cmake_minimum_required (VERSION 2.8.11)
project (glRenderGlutApp)

add_compile_options(-std=c++11)

add_subdirectory (libs/glRender)
add_subdirectory (app)
