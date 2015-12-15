cmake_minimum_required(VERSION 3.0)

add_library(libpietvm)
target_compile_features(libpietvm PRIVATE cxx_defaulted_move_initializers)
target_include_directories(libpietvm PRIVATE include)
target_sources(libpietvm PRIVATE src/persistency/Color.cpp src/persistency/ColorPalette.cpp)