cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 11)
project(CXXLAPACK VERSION 0.1 DESCRIPTION "C++ interface to LAPACK functions" LANGUAGES CXX C Fortran)

include(cmake/common.cmake)

include(cmake/options.cmake)

include(cmake/flags.cmake)

configure_file(CXXLAPACK_config.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/CXXLAPACK_config.h)
include(GNUInstallDirs)

if (CXXLAPACK_LAPACK)
    add_subdirectory(src)
    target_include_directories(cxxlapack PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
                                                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
endif()

if (CXXLAPACK_TEMPLATES)
    set(CMAKE_CXX_STANDARD 17)
    find_package(OpenMP COMPONENTS CXX REQUIRED)
    add_subdirectory(../CXXBLAS ${CMAKE_CURRENT_BINARY_DIR}/CXXBLAS)
    #find_package(CXXBLAS REQUIRED)
    if (NOT CXXLAPACK_LAPACK)
        add_library(cxxlapack INTERFACE)
        target_link_libraries(cxxlapack INTERFACE OpenMP::OpenMP_CXX BLAS::BLAS_CXX)
        target_compile_definitions(cxxlapack INTERFACE $<$<CONFIG:Debug>:DEBUG>)
        target_include_directories(cxxlapack INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                       $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
                                                       $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
    else()
        target_link_libraries(cxxlapack PUBLIC OpenMP::OpenMP_CXX BLAS::BLAS_CXX)
    endif()
endif()


add_library(LAPACK::LAPACK_CXX ALIAS cxxlapack)

include(cmake/install.cmake)
