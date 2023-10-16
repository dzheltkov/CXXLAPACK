#ifndef CXXLAPACK_AUXILIARY_LARFG_HPP
#define CXXLAPACK_AUXILIARY_LARFG_HPP
#include <CXXBLAS.hpp>
#include <type_traits>
#include <cmath>
#include <algorithm>
#include <limits>

namespace LAPACK
{
	// Reflection (I - \tau u u*)[alpha x]^T = [beta 0]^T, size(x) = n - 1
	// so that u = [1 ***], beta = sgn(Re(alpha)) * sqrt(|alpha|^2 + ||x||^2)
    template <class DataType> 
        void larfg(const CXXLAPACK_INT &n,
                   DataType &alpha,
                   DataType *x,
                   const CXXLAPACK_INT &incx,
                   DataType &tau)
        {
            typedef decltype(std::abs(DataType())) RealType;
            RealType xnorm = BLAS::nrm2(n - 1, x, incx);
            if (xnorm == 0 && std::imag(alpha) == 0)
            {
                tau = 0;
                return;
            }
            RealType beta = std::max(xnorm, std::max(std::real(alpha), std::imag(alpha)));
            beta = beta * sqrt((xnorm / beta) * (xnorm / beta) + (std::real(alpha) / beta) * (std::real(alpha) / beta) + (std::imag(alpha) / beta) * (std::imag(alpha) / beta));
            if (std::real(alpha) > 0)
            {
                beta = -beta;
            }
            int exp;
            std::frexp(beta, &exp);
            RealType Beta = std::ldexp(beta, -exp);
            DataType Alpha;
            if (std::is_same<RealType, DataType>::value)
            {
                Alpha = std::ldexp(std::real(alpha), -exp);
            }
            else
            {
                Alpha = DataType(std::ldexp(std::real(alpha), -exp), std::ldexp(std::imag(alpha), -exp));
            }
            tau = DataType((Beta - std::real(Alpha)) / Beta, -std::imag(Alpha) / Beta);
            alpha = DataType(1.0) / (Alpha - Beta);
            for (CXXLAPACK_INT i = 0; i < n - 1; i++)
            {
                x[i * incx] *= alpha;
            }
            alpha = beta;
        }
}
#endif
