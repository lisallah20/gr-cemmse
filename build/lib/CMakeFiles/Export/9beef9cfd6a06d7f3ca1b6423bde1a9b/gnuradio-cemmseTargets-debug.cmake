#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gnuradio::gnuradio-cemmse" for configuration "Debug"
set_property(TARGET gnuradio::gnuradio-cemmse APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(gnuradio::gnuradio-cemmse PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgnuradio-cemmse.so.1.0.0.0"
  IMPORTED_SONAME_DEBUG "libgnuradio-cemmse.so.1.0.0"
  )

list(APPEND _cmake_import_check_targets gnuradio::gnuradio-cemmse )
list(APPEND _cmake_import_check_files_for_gnuradio::gnuradio-cemmse "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgnuradio-cemmse.so.1.0.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
