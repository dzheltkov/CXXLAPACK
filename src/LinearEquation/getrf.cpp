#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define sgetrf LAPACK_GLOBAL(sgetrf,SGETRF)
#define dgetrf LAPACK_GLOBAL(dgetrf,DGETRF)
#define cgetrf LAPACK_GLOBAL(cgetrf,CGETRF)
#define zgetrf LAPACK_GLOBAL(zgetrf,ZGETRF)

extern "C"
{
    void sgetrf(const CXXLAPACK_INT &m,
                const CXXLAPACK_INT &n,
                float *A, const CXXLAPACK_INT &ldA,
                CXXLAPACK_INT *ipiv,
                CXXLAPACK_INT &info);

    void dgetrf(const CXXLAPACK_INT &m,
                const CXXLAPACK_INT &n,
                double *A, const CXXLAPACK_INT &ldA,
                CXXLAPACK_INT *ipiv,
                CXXLAPACK_INT &info);

    void cgetrf(const CXXLAPACK_INT &m,
                const CXXLAPACK_INT &n,
                std::complex<float> *A, const CXXLAPACK_INT &ldA,
                CXXLAPACK_INT *ipiv,
                CXXLAPACK_INT &info);

    void zgetrf(const CXXLAPACK_INT &m,
                const CXXLAPACK_INT &n,
                std::complex<double> *A, const CXXLAPACK_INT &ldA,
                CXXLAPACK_INT *ipiv,
                CXXLAPACK_INT &info);
}

namespace LAPACK
{
    CXXLAPACK_INT getrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        float *A, const CXXLAPACK_INT &ldA,
                        CXXLAPACK_INT *ipiv)
    {
        CXXLAPACK_INT info;
        sgetrf(m, n, A, ldA, ipiv, info);
        return info;
    }

    CXXLAPACK_INT getrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        double *A, const CXXLAPACK_INT &ldA,
                        CXXLAPACK_INT *ipiv)
    {
        CXXLAPACK_INT info;
        dgetrf(m, n, A, ldA, ipiv, info);
        return info;
    }

    CXXLAPACK_INT getrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        CXXLAPACK_INT *ipiv)
    {
        CXXLAPACK_INT info;
        cgetrf(m, n, A, ldA, ipiv, info);
        return info;
    }

    CXXLAPACK_INT getrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<double> *A, const CXXLAPACK_INT &ldA,
                        CXXLAPACK_INT *ipiv)
    {
        CXXLAPACK_INT info;
        zgetrf(m, n, A, ldA, ipiv, info);
        return info;
    }
}
