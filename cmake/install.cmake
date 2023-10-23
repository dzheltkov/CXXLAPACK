include(GNUInstallDirs)
target_include_directories(cxxlapack PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                            $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
                                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

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
