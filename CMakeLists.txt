cmake_minimum_required(VERSION 3.19)
project(cinedot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Include FetchContent, and use it to download the Godot bindings.
include(FetchContent)

FetchContent_Declare(
    GDExtension
    GIT_REPOSITORY https://github.com/godotengine/godot-cpp.git
    GIT_TAG 4.3
)

FetchContent_MakeAvailable(GDExtension)

add_subdirectory(src)