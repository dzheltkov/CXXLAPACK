cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 17)
project(CXXLAPACK VERSION 0.1 DESCRIPTION "C++ interface to LAPACK functions" LANGUAGES CXX C Fortran)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) \
and run CMake from there."
  )
endif()

option(USE_ASAN "Use sanitizers" OFF)
option(USE_FCHECK "Use Fortran checks" OFF)
option(CXXLAPACK_TEMPLATES "Enable templates to work with arbitrary datatypes" OFF)
option(CXXLAPACK_LAPACK "Use LAPACK as backend for standard datatypes" ON)
option(CXXLAPACK_64BIT "Use 64 bit integers for LAPACK" OFF)

if(NOT CXXLAPACK_TEMPLATES AND NOT CXXLAPACK_LAPACK)
  message(
    FATAL_ERROR
    "At least one of the options CXXLAPACK_TEMPLATES or CXXLAPACK_LAPACK should be set"
  )
endif()

if (CXXLAPACK_64BIT)
    set(CXXLAPACK_INT int64_t)
    set(BLA_SIZEOF_INTEGER 8)
else()
    set(CXXLAPACK_INT int32_t)
    set(BLA_SIZEOF_INTEGER 8)
endif()

if (NOT CMAKE_BUILD_TYPE) # if CMAKE_BUILD_TYPE is undefined
    set(CMAKE_BUILD_TYPE Release) # set it to Release
endif()

include(GNUInstallDirs)


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS_DEBUG "-Og -g -Wall -Wextra -pedantic")
    if (USE_ASAN)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitiza-recover")
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel" OR CMAKE_CXX_COMPILER_ID STREQUAL "IntelLLVM")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall")
endif()

if (CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_Fortran_FLAGS_DEBUG "-Og -g -Wall -Wextra -pedantic")
    if (USE_ASAN)
        set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fsanitize=address -fsanitiza-recover")
    endif()
    if (USE_FCHECK)
        set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fcheck=all")
    endif()
elseif (CMAKE_Fortran_COMPILER_ID STREQUAL "Intel" OR CMAKE_Fortran_COMPILER_ID STREQUAL "IntelLLVM")
    set(CMAKE_Fortran_FLAGS_DEBUG "-O0 -g -warn all")
    if (USE_FCHECK)
        set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -check all")
    endif()
endif()

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS_DEBUG "-Og -g -Wall -Wextra -pedantic")
    if (USE_ASAN)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitiza-recover")
    endif()
elseif (CMAKE_C_COMPILER_ID STREQUAL "Intel" OR CMAKE_C_COMPILER_ID STREQUAL "IntelLLVM")
    set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall")
endif()

configure_file(CXXLAPACK_config.h.in ${PROJECT_BINARY_DIR}/include/CXXLAPACK_config.h)

if (CXXLAPACK_LAPACK)
    enable_language(C)
    enable_language(Fortran)
    include(FortranCInterface)
    FortranCInterface_VERIFY(CXX)
    find_package(LAPACK REQUIRED)
    FortranCInterface_HEADER(mangleinclude/LAPACKFortranMangle.h MACRO_NAMESPACE "LAPACK_")

    add_library(cxxlapack src/Auxiliary/lacgv.cpp
                          src/Auxiliary/larfg.cpp
                          src/Auxiliary/lartg.cpp
                          src/LinearEquation/tptrs.cpp
                          src/LeastSquares/unmqr.cpp
    )

    target_include_directories(cxxlapack PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/mangleinclude)
    target_link_libraries(cxxlapack PUBLIC LAPACK::LAPACK)
endif()

if (CXXLAPACK_TEMPLATES)
    find_package(OpenMP COMPONENTS CXX REQUIRED)
    if (NOT CXXLAPACK_LAPACK)
        add_library(cxxlapack INTERFACE)
    endif()
    find_package(CXXBLAS REQUIRED)
    target_link_libraries(cxxlapack OpenMP::OpenMP_CXX)
endif()


target_include_directories(cxxlapack PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                            $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
                                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_definitions(cxxlapack PRIVATE $<$<CONFIG:Debug>:DEBUG>)
add_library(LAPACK::LAPACK_CXX ALIAS cxxlapack)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY "${PROJECT_BINARY_DIR}/include/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
        TARGETS cxxlapack
        EXPORT CXXLAPACKTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

    set(CXXLAPACK_CMAKE_PACKAGE_INSTALL_SUBDIR "share/CXXLAPACK/cmake")

install(
    EXPORT CXXLAPACKTargets
        NAMESPACE ::
        DESTINATION ${CXXLAPACK_CMAKE_PACKAGE_INSTALL_SUBDIR})

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
                                 CXXLAPACKConfigVersion.cmake
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMinorVersion)

configure_package_config_file(
                              "${PROJECT_SOURCE_DIR}/cmake/CXXLAPACKConfig.cmake.in" CXXLAPACKConfig.cmake
                              INSTALL_DESTINATION ${CXXLAPACK_CMAKE_PACKAGE_INSTALL_SUBDIR})

install(FILES "${PROJECT_BINARY_DIR}/CXXLAPACKConfig.cmake"
              "${PROJECT_BINARY_DIR}/CXXLAPACKConfigVersion.cmake"
        DESTINATION ${CXXLAPACK_CMAKE_PACKAGE_INSTALL_SUBDIR})

