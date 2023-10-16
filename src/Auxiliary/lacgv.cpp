#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define clacgv LAPACK_GLOBAL(clacgv,CLACGV)
#define zlacgv LAPACK_GLOBAL(zlacgv,ZLACGV)

extern "C"
{
    void clacgv(const CXXLAPACK_INT &n,
               std::complex<float> *x,
               const CXXLAPACK_INT &incx);

    void zlacgv(const CXXLAPACK_INT &n,
                std::complex<double> *x,
                const CXXLAPACK_INT &incx);
}

namespace LAPACK
{
    void lacgv(const CXXLAPACK_INT &n,
               float *x,
               const CXXLAPACK_INT &incx)
    {
        (void) (n);
        (void) (x);
        (void) (incx);
    }

    void lacgv(const CXXLAPACK_INT &n,
               double *x,
               const CXXLAPACK_INT &incx)
    {
        (void) (n);
        (void) (x);
        (void) (incx);
    }

    void lacgv(const CXXLAPACK_INT &n,
               std::complex<float> *x,
               const CXXLAPACK_INT &incx)
    {
        clacgv(n, x, incx);
    }

    void lacgv(const CXXLAPACK_INT &n,
               std::complex<double> *x,
               const CXXLAPACK_INT &incx)
    {
        zlacgv(n, x, incx);
    }
}
