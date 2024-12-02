# SHARED LIBRARY CMAKE

# Add source to this project's library.
add_library (shared
    "inputtaker.h"
    "inputtaker.cpp"
 "utils.cpp" "utils.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET shared PROPERTY CXX_STANDARD 20)
endif()