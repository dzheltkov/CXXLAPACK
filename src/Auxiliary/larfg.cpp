#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define slarfg LAPACK_GLOBAL(slarfg,SLARFG)
#define dlarfg LAPACK_GLOBAL(dlarfg,DLARFG)
#define clarfg LAPACK_GLOBAL(clarfg,CLARFG)
#define zlarfg LAPACK_GLOBAL(zlarfg,ZLARFG)

extern "C"
{
    void slarfg(const CXXLAPACK_INT &n,
                float &alpha,
                float *x,
                const CXXLAPACK_INT &incx,
                float &tau);

    void dlarfg(const CXXLAPACK_INT &n,
                double &alpha,
                double *x,
                const CXXLAPACK_INT &incx,
                double &tau);

    void clarfg(const CXXLAPACK_INT &n,
                std::complex<float> &alpha,
                std::complex<float> *x,
                const CXXLAPACK_INT &incx,
                std::complex<float> &tau);

    void zlarfg(const CXXLAPACK_INT &n,
                std::complex<double> &alpha,
                std::complex<double> *x,
                const CXXLAPACK_INT &incx,
                std::complex<double> &tau);
}

namespace LAPACK
{
    void larfg(const CXXLAPACK_INT &n,
               float &alpha,
               float *x,
               const CXXLAPACK_INT &incx,
               float &tau)
    {
        slarfg(n, alpha, x, incx, tau);
    }

    void larfg(const CXXLAPACK_INT &n,
               double &alpha,
               double *x,
               const CXXLAPACK_INT &incx,
               double &tau)
    {
        dlarfg(n, alpha, x, incx, tau);
    }

    void larfg(const CXXLAPACK_INT &n,
            std::complex<float> &alpha,
            std::complex<float> *x,
            const CXXLAPACK_INT &incx,
            std::complex<float> &tau)
    {
        clarfg(n, alpha, x, incx, tau);
    }

    void larfg(const CXXLAPACK_INT &n,
               std::complex<double> &alpha,
               std::complex<double> *x,
               const CXXLAPACK_INT &incx,
               std::complex<double> &tau)
    {
        zlarfg(n, alpha, x, incx, tau);
    }
}
