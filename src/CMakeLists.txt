enable_language(C)
enable_language(Fortran)
include(FortranCInterface)
FortranCInterface_VERIFY(CXX)
find_package(LAPACK REQUIRED)
FortranCInterface_HEADER(mangleinclude/LAPACKFortranMangle.h MACRO_NAMESPACE "LAPACK_")

add_library(cxxlapack LAPACK_compatability.f90
                      Auxiliary/lacgv.cpp
                      Auxiliary/lacpy.cpp
                      Auxiliary/larfg.cpp
                      Auxiliary/lartg.cpp
                      Auxiliary/lanhe.cpp
                      Auxiliary/laqhe.cpp
                      LinearEquation/tptrs.cpp
                      LinearEquation/potrf.cpp
                      LinearEquation/potrs.cpp
                      LinearEquation/poequ.cpp
                      LinearEquation/poequb.cpp
                      LeastSquares/unmqr.cpp
                      OrthogonalFactorizations/geqrf.cpp
                      OrthogonalFactorizations/ungqr.cpp
                      OrthogonalFactorizations/geqp3rk.cpp
)

target_include_directories(cxxlapack PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/mangleinclude)
target_link_libraries(cxxlapack PUBLIC LAPACK::LAPACK)
target_compile_definitions(cxxlapack PRIVATE $<$<CONFIG:Debug>:DEBUG>)
