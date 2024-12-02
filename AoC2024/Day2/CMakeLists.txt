# CMakeList.txt : CMake project for Day1, include source and define

# Add source to this project's executable.
add_executable (Day2 "main.cpp" "part1.cpp" "part2.cpp" )

target_link_libraries(Day2 PUBLIC shared)
target_include_directories(Day2 PUBLIC "${PROJECT_SOURCE_DIR}/shared")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Day2 PROPERTY CXX_STANDARD 20)
endif()