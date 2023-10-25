
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

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
                                 ${CMAKE_CURRENT_BINARY_DIR}/CXXLAPACKConfigVersion.cmake
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMinorVersion)

configure_package_config_file(
                              "${PROJECT_SOURCE_DIR}/cmake/CXXLAPACKConfig.cmake.in" ${CMAKE_CURRENT_BINARY_DIR}/CXXLAPACKConfig.cmake
                              INSTALL_DESTINATION ${CXXLAPACK_CMAKE_PACKAGE_INSTALL_SUBDIR})

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/CXXLAPACKConfig.cmake"
              "${CMAKE_CURRENT_BINARY_DIR}/CXXLAPACKConfigVersion.cmake"
        DESTINATION ${CXXLAPACK_CMAKE_PACKAGE_INSTALL_SUBDIR})
