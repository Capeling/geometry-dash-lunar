cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(geometry-dash-lunar VERSION 1.0.0)

# source files
file(GLOB_RECURSE SOURCES
	src/main.cpp
    src/hooks/*.cpp
    src/defs/*.cpp
    src/utils/*.cpp
    src/layers/*.cpp
    src/nodes/*.cpp
    ${OS_SOURCES}
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set(GEODE_BINDINGS_REPO_PATH "S:/GitHub/Geode/bindings")
if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

CPMAddPackage("gh:dankmeme01/uibuilder#main")
target_link_libraries(${PROJECT_NAME} UIBuilder)

setup_geode_mod(${PROJECT_NAME})
