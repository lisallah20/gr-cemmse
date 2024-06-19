find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_CEMMSE gnuradio-cemmse)

FIND_PATH(
    GR_CEMMSE_INCLUDE_DIRS
    NAMES gnuradio/cemmse/api.h
    HINTS $ENV{CEMMSE_DIR}/include
        ${PC_CEMMSE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_CEMMSE_LIBRARIES
    NAMES gnuradio-cemmse
    HINTS $ENV{CEMMSE_DIR}/lib
        ${PC_CEMMSE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-cemmseTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_CEMMSE DEFAULT_MSG GR_CEMMSE_LIBRARIES GR_CEMMSE_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_CEMMSE_LIBRARIES GR_CEMMSE_INCLUDE_DIRS)
