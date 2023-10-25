cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 17)
project(CXXLAPACK VERSION 0.1 DESCRIPTION "C++ interface to LAPACK functions" LANGUAGES CXX C Fortran)

include(cmake/common.cmake)

include(cmake/options.cmake)

include(cmake/flags.cmake)

configure_file(CXXLAPACK_config.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/CXXLAPACK_config.h)

if (CXXLAPACK_LAPACK)
    add_subdirectory(src)
endif()

if (CXXLAPACK_TEMPLATES)
    find_package(OpenMP COMPONENTS CXX REQUIRED)
    if (NOT CXXLAPACK_LAPACK)
        add_library(cxxlapack INTERFACE)
    endif()
    find_package(CXXBLAS REQUIRED)
    target_link_libraries(cxxlapack OpenMP::OpenMP_CXX)
endif()


target_compile_definitions(cxxlapack PRIVATE $<$<CONFIG:Debug>:DEBUG>)
add_library(LAPACK::LAPACK_CXX ALIAS cxxlapack)

include(cmake/install.cmake)
