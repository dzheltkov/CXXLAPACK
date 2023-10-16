#ifndef CXXLAPACK_AUXILIARY_HPP
#define CXXLAPACK_AUXILIARY_HPP
#include <type_traits>
namespace LAPACK
{
    template<class DataType>
        void lacgv(const CXXLAPACK_INT &n,
                   DataType *x,
                   const CXXLAPACK_INT &incx);

    template <class DataType> 
        void larfg(const CXXLAPACK_INT &n,
                   DataType &alpha,
                   DataType *x,
                   const CXXLAPACK_INT &incx,
                   DataType &tau);

    template <class DataType>
        void lartg(const DataType &a,
                   const DataType &b,
                   decltype(std::abs(DataType())) &c,
                   DataType &s,
                   DataType &r);
}

#include "Auxiliary/lacgv.hpp"
#include "Auxiliary/larfg.hpp"
#include "Auxiliary/lartg.hpp"
#endif

