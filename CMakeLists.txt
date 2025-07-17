cmake_minimum_required(VERSION 3.10)
project(sim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include all headers from the 'include' folder
include_directories(include)

# Collect all .cpp source files recursively from src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Create the executable from all source files
add_executable(sim ${SOURCES})

# Find and link SFML libraries
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
target_link_libraries(sim sfml-graphics sfml-window sfml-system)
