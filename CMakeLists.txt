cmake_minimum_required(VERSION 3.1)

project(Groupong)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Groupong main.cpp)
target_link_libraries(Groupong sfml-graphics sfml-audio)
