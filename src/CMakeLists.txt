enable_language(C)
enable_language(Fortran)
include(FortranCInterface)
FortranCInterface_VERIFY(CXX)
find_package(LAPACK REQUIRED)
FortranCInterface_HEADER(mangleinclude/LAPACKFortranMangle.h MACRO_NAMESPACE "LAPACK_")

add_library(cxxlapack Auxiliary/lacgv.cpp
                      Auxiliary/larfg.cpp
                      Auxiliary/lartg.cpp
                      LinearEquation/tptrs.cpp
                      LinearEquation/potrf.cpp
                      LeastSquares/unmqr.cpp
)

target_include_directories(cxxlapack PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/mangleinclude)
target_link_libraries(cxxlapack PUBLIC LAPACK::LAPACK)
target_compile_definitions(cxxlapack PRIVATE $<$<CONFIG:Debug>:DEBUG>)
