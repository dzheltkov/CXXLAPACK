# C++ interface and template implementation of LAPACK library

## Contents

0. [Minimal prerequisites](#min-prereq)
1. [Quick start](#quick-start)

____

## Minimal prerequisites
- CMake version 3.22 or newer.
- C++-11 compiler with OpenMP support.
- To use LAPACK interface also LAPACK implementation and interoperable C and Fortran compilers are required.

____

## Quick start

C++ Library can be build and installed using the following commands:
```
mkdir build
cd build
cmake ..
cmake --build .
cmake --install . --prefix /path/to/install
```

For detailed information about installation refer INSTALL.md
