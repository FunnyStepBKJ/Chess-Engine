# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/chess_engine_ui_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/chess_engine_ui_autogen.dir/ParseCache.txt"
  "chess_engine_ui_autogen"
  )
endif()
