cmake_minimum_required(VERSION 3.5)
project("m_cpp_haptic")

# Options
option(GEN_DOCS "Generate documentation" OFF)
option(BUILD_SHARED_LIBS  "Build using shared libraries" ON)

set(OUT_DIR "/out")

# add common.cmake
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/" ${CMAKE_MODULE_PATH})
include(common)

# --------------------------------------------------------------
# project structure
# --------------------------------------------------------------

add_subdirectory(myApi)
add_subdirectory(myDemo)