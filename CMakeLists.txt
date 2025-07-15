cmake_minimum_required(VERSION 3.10)
project(sim)
set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(sim main.cpp)
target_link_libraries(sim sfml-graphics sfml-window sfml-system)