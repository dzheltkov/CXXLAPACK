#ifndef CXXLAPACK_HPP
#define CXXLAPACK_HPP
#include <complex>
#include "CXXLAPACK_config.h"

#ifdef CXXLAPACK_LAPACK
#include "CXXLAPACK/Auxiliary.h"
#include "CXXLAPACK/LeastSquares.h"
#include "CXXLAPACK/LinearEquation.h"
#endif

#ifdef CXXLAPACK_TEMPLATES
#include "CXXLAPACK/Auxiliary.hpp"
//#include "CXXLAPACK/LeastSquares.hpp"
//#include "CXXLAPACK/LinearEquation.hpp"
#endif
#endif
