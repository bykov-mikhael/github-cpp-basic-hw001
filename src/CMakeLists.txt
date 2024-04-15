cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(${src} VERSION 0.0.1)

add_executable(${src}
  class001.cpp
)

target_compile_features(${src} PUBLIC
  cxx_std_17
)

set_target_properties(${src} PROPERTIES
  CXX_STANDARD_REQUIRED ON
)

set_target_properties(${src} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

# параметры директивы include
target_include_directories(
  ${src} PRIVATE
  ${CMAKE_SOURCE_DIR}/include/cstr

  # ${CMAKE_SOURCE_DIR}/include/server
)

# параметры компановщика/линковщика:
# парамтеры библотек должны совпадать с названием в add_library(shared_lib SHARED, add_library(static_lib STATIC
target_link_libraries(
  ${src}
  ${include_cstr}

  # ${include_gui}
)

# параметры директивы include
# target_include_directories(
# server PRIVATE
# ${CMAKE_CURRENT_BINARY_DIR}       # ссылка на config.h.in
# ${CMAKE_SOURCE_DIR}/shared-lib    # ссылка на shared-lib
# ${CMAKE_SOURCE_DIR}/static-lib    # ссылка на static-lib
# )

# параметры компановщика/линковщика:
# парамтеры библотек должны совпадать с названием в add_library(shared_lib SHARED, add_library(static_lib STATIC
# target_link_libraries(server
# static_lib
# shared_lib
# )
if(MSVC)
  target_compile_options(${src} PUBLIC /W4 /WX)
else()
  target_compile_options(${src} PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
