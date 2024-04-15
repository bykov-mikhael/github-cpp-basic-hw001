cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(${include_cstr} VERSION 0.0.1)

add_library(${include_cstr} SHARED cstr.cpp cstr.hpp)

target_compile_features(${include_cstr}
  PUBLIC
  cxx_std_17
)

set_target_properties(${include_cstr} PROPERTIES
  CXX_STANDARD_REQUIRED ON
)

if(MSVC)
  target_compile_options(${include_cstr} PUBLIC /W4 /WX)
else()
  target_compile_options(${include_cstr} PUBLIC -Wall -Wextra -pedantic -Werror) #
endif()