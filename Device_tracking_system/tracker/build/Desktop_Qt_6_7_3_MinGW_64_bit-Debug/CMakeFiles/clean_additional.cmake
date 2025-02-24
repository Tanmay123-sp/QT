# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\tracker_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tracker_autogen.dir\\ParseCache.txt"
  "Details\\CMakeFiles\\Details_autogen.dir\\AutogenUsed.txt"
  "Details\\CMakeFiles\\Details_autogen.dir\\ParseCache.txt"
  "Details\\Details_autogen"
  "tracker_autogen"
  )
endif()
