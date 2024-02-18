# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MelodiMix_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MelodiMix_autogen.dir/ParseCache.txt"
  "MelodiMix_autogen"
  )
endif()
