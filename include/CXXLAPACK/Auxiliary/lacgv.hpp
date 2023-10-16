#ifndef CXXLAPACK_AUXILIARY_LACGV_HPP
#define CXXLAPACK_AUXILIARY_LACGV_HPP
#include <type_traits>

namespace LAPACK
{
    template<class DataType>
        void lacgv(const CXXLAPACK_INT &n,
                   DataType *x,
                   const CXXLAPACK_INT &incx)
        {
            typedef decltype(std::abs(DataType())) RealType;
            if constexpr (!std::is_same<RealType, DataType>::value)
            {
                for (CXXLAPACK_INT j = 0; j < n; j += incx)
                {
                    x[j] = std::conj(x[j]);
                }
            }
            else
            {
                (void)(n);
                (void)(x);
                (void)(incx);
            }
        }
}
#endif
