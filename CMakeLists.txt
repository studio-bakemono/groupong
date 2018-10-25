cmake_minimum_required(VERSION 3.1)

project(groupong)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

file(GLOB SOURCES "*.cpp")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(pong ${SOURCES} )
target_link_libraries(pong sfml-graphics sfml-audio)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

file(GLOB SFML_DLL "SFML/*.dll")
file(COPY ${SFML_DLL} DESTINATION ${CMAKE_BINARY_DIR})
