# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appGizWebPluginLab2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appGizWebPluginLab2_autogen.dir\\ParseCache.txt"
  "appGizWebPluginLab2_autogen"
  "src\\CMakeFiles\\src_lib_autogen.dir\\AutogenUsed.txt"
  "src\\CMakeFiles\\src_lib_autogen.dir\\ParseCache.txt"
  "src\\src_lib_autogen"
  )
endif()
