# CMakeList.txt : Top-level CMake project file, do global configuration

cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AoC2024")

# Include sub-projects.
add_subdirectory ("shared")
add_subdirectory ("Day1")
add_subdirectory ("Day2")
add_subdirectory ("Day3")
add_subdirectory ("Day4")
add_subdirectory ("Day5")
add_subdirectory ("Day6")
add_subdirectory ("Day7")
add_subdirectory ("Day8")
add_subdirectory ("Day9")
add_subdirectory ("Day10")
add_subdirectory ("Day11")
add_subdirectory ("Day12")