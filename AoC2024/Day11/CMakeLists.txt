﻿# CMakeList.txt : CMake project for Day1, include source and define

# Add source to this project's executable.
add_executable (Day11 "main.cpp" "part1.cpp" "part2.cpp" "common.cpp" "common.h")

target_link_libraries(Day11 PUBLIC shared)
target_include_directories(Day11 PUBLIC "${PROJECT_SOURCE_DIR}/shared")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Day11 PROPERTY CXX_STANDARD 20)
endif()