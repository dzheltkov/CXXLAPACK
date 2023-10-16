#ifndef CXXLAPACK_AUXILIARY_LARTG_HPP
#define CXXLAPACK_AUXILIARY_LARTG_HPP
#include <type_traits>
#include <cmath>
#include <algorithm>
#include <limits>

namespace LAPACK
{
    // Rotation [c s // -s^H c] * [a b]^T = [r 0]^T , 
    template <class DataType>
        void lartg(const DataType &a,
                   const DataType &b,
                   decltype(std::abs(DataType())) &c,
                   DataType &s,
                   DataType &r)
        {
            typedef decltype(std::abs(DataType())) RealType;
            RealType mx = std::max(std::abs(std::real(a)), std::abs(std::real(b)));
            if (!std::is_same<RealType, DataType>::value)
            {
                mx = std::max(mx, std::abs(std::imag(a)));
                mx = std::max(mx, std::abs(std::imag(b)));
            }
            if (mx == 0)
            {
                c = 1.0;
                s = DataType(0.0);
                r = DataType(0.0);
                return;
            }
            int exp;
            std::frexp(mx, &exp);
            DataType A, B;
            if (std::is_same<RealType, DataType>::value)
            {
                A = std::ldexp(std::real(a), -exp);
                B = std::ldexp(std::real(b), -exp);
            }
            else
            {
                A = DataType(std::ldexp(std::real(a), -exp), std::ldexp(std::imag(a), -exp));
                B = DataType(std::ldexp(std::real(b), -exp), std::ldexp(std::imag(b), -exp));
            }
            if (std::abs(A) < std::numeric_limits<RealType>::epsilon())
            {
                c = 0.0;
                s = std::conj(b) / std::abs(b);
                r = abs(b);
                return;
            }
            if (std::abs(B) < std::numeric_limits<RealType>::epsilon())
            {
                c = 1.0;
                s = DataType(0.0);
                r = DataType(0.0);
                return;                
            }
            RealType R = std::sqrt(std::norm(A) + std::norm(B));
            DataType alpha = A / std::abs(A);
            RealType S = RealType(1.0) / R;
            c = std::abs(A) * S;
            s = std::conj(B) * alpha * S;
            r = alpha * std::ldexp(R, exp);
        }
}
#endif
