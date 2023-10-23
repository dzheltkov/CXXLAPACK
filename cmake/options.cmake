option(CXXLAPACK_ASAN "Use sanitizers" OFF)
option(CXXLAPACK_FCHECK "Use Fortran checks" OFF)
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
    if (CXXLAPACK_LAPACK)
        set(BLA_SIZEOF_INTEGER 8)
    endif()
else()
    set(CXXLAPACK_INT int32_t)
    if (CXXLAPACK_LAPACK)
        set(BLA_SIZEOF_INTEGER 4)
    endif()
endif()
