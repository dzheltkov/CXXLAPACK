#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define spotrs LAPACK_GLOBAL(spotrs,SPOTRS)
#define dpotrs LAPACK_GLOBAL(dpotrs,DPOTRS)
#define cpotrs LAPACK_GLOBAL(cpotrs,CPOTRS)
#define zpotrs LAPACK_GLOBAL(zpotrs,ZPOTRS)

extern "C"
{
    void spotrs(const char &uplo,
                const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &nrhs,
                const float *A, const CXXLAPACK_INT &ldA,
                float *B, const CXXLAPACK_INT &ldB,
                CXXLAPACK_INT &info);

    void dpotrs(const char &uplo,
                const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &nrhs,
                const double *A, const CXXLAPACK_INT &ldA,
                double *B, const CXXLAPACK_INT &ldB,
                CXXLAPACK_INT &info);

    void cpotrs(const char &uplo,
                const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &nrhs,
                const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                std::complex<float> *B, const CXXLAPACK_INT &ldB,
                CXXLAPACK_INT &info);

    void zpotrs(const char &uplo,
                const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &nrhs,
                const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                std::complex<double> *B, const CXXLAPACK_INT &ldB,
                CXXLAPACK_INT &info);
}

namespace LAPACK
{
    CXXLAPACK_INT potrs(const char &uplo,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const float *A, const CXXLAPACK_INT &ldA,
                        float *B, const CXXLAPACK_INT &ldB)
    {
        CXXLAPACK_INT info;
        spotrs(uplo, n, nrhs, A, ldA, B, ldB, info);
        return info;
    }

    CXXLAPACK_INT potrs(const char &uplo,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const double *A, const CXXLAPACK_INT &ldA,
                        double *B, const CXXLAPACK_INT &ldB)
    {
        CXXLAPACK_INT info;
        dpotrs(uplo, n, nrhs, A, ldA, B, ldB, info);
        return info;
    }

    CXXLAPACK_INT potrs(const char &uplo,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        std::complex<float> *B, const CXXLAPACK_INT &ldB)
    {
        CXXLAPACK_INT info;
        cpotrs(uplo, n, nrhs, A, ldA, B, ldB, info);
        return info;
    }

    CXXLAPACK_INT potrs(const char &uplo,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                        std::complex<double> *B, const CXXLAPACK_INT &ldB)
    {
        CXXLAPACK_INT info;
        zpotrs(uplo, n, nrhs, A, ldA, B, ldB, info);
        return info;
    }
}
