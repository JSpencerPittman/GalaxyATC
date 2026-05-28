cmake_minimum_required(VERSION 3.28)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_GENERATOR "Ninja")

project(GalaxyATC VERSION 1.0)

find_package(SDL2 REQUIRED)
get_property(all_targets DIRECTORY . PROPERTY BUILDSYSTEM_TARGETS)
message(STATUS "Targets: ${all_targets}")

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(GalaxyATC ${SOURCES})

target_include_directories(GalaxyATC PUBLIC include)

target_link_libraries(GalaxyATC PUBLIC SDL2::SDL2)