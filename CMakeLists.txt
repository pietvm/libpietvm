cmake_minimum_required(VERSION 3.0)

add_library(libpietvm)
file(GLOB libpietvmSources "src/*.cpp" "src/*.c")
target_include_directories(libpietvm PRIVATE include)
target_sources(libpietvm PRIVATE ${libpietvmSources})