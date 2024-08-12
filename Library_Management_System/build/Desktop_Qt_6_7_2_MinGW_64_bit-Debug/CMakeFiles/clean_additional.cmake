# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Assign__1_autogen"
  "CMakeFiles\\Assign__1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Assign__1_autogen.dir\\ParseCache.txt"
  )
endif()
