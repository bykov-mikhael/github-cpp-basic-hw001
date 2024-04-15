cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(github-cpp-basix-hw001 VERSION 0.0.1)

set(src "class001")
set(include_cstr "cstr")

# set(include_gui "gui")
add_subdirectory(src)

add_subdirectory(include/cstr)

# add_subdirectory(include/gui)