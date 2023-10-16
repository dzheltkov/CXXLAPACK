## Contents

0. [Prerequisites](#prereq)
1. [Compilation](#compilation)
2. [Installation](#install)
____

## Prerequisites

Minimal prerequisites includes:
- CMake version 3.22 or newer.
- C++-17 compiler with OpenMP support.
- To use LAPACK interface also LAPACK implementation and interoperable C and Fortran compilers are required.

## Compilation


Library can be built using the following commands:
```
mkdir build
cd build
cmake ..
cmake --build .
```

Template implementation of LAPACK functions can be enabled using `-DCXXLAPACK_TEMPLATES=On` during CMake project configuration.

64-bit integer for LAPACK can be enabled using `-DCXXLAPACK_64BIT=On` during CMake project configuration.

Address sanitizers can be enabled using `-DCXXLAPACK_ASAN=On` during CMake project configuration.

Fortran checks can be enabled using `-DCXXLAPACK_FCHECK=On` during CMake project configuration.

Interface to LAPACK implementation can be disabled using `-DCXXLAPACK_LAPACK=Off` during CMake project configuration.

At leas one of the `CXXLAPACK_LAPACK` and `CXXLAPACK_TEMPLATES` should be set on.

For example, both template implementation and interface to LAPACK implementation can be included using
```
mkdir build
cd build
cmake -DBUILD_TEMPLATES=On ..
cmake --build .
```

## Instalation
Library can be installed using the following command in build directory
```
cmake --prefix=<path> .
```
