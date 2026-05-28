cmake_minimum_required(VERSION 3.28)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_GENERATOR "Ninja")

project(GalaxyATC VERSION 1.0)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(GalaxyATC ${SOURCES})

add_custom_command(
    TARGET GalaxyATC PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/resources)

target_include_directories(GalaxyATC PUBLIC include)

target_link_libraries(GalaxyATC PUBLIC SDL2::SDL2 SDL2_ttf::SDL2_ttf)