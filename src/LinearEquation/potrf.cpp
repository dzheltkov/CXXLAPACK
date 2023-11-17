#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define spotrf LAPACK_GLOBAL(spotrf,SPOTRF)
#define dpotrf LAPACK_GLOBAL(dpotrf,DPOTRF)
#define cpotrf LAPACK_GLOBAL(cpotrf,CPOTRF)
#define zpotrf LAPACK_GLOBAL(zpotrf,ZPOTRF)

extern "C"
{
    void spotrf(const char &uplo,
                const CXXLAPACK_INT &n,
                float *A, const CXXLAPACK_INT &ldA,
                CXXLAPACK_INT &info);

    void dpotrf(const char &uplo,
                const CXXLAPACK_INT &n,
                double *A, const CXXLAPACK_INT &ldA,
                CXXLAPACK_INT &info);

    void cpotrf(const char &uplo,
                const CXXLAPACK_INT &n,
                std::complex<float> *A, const CXXLAPACK_INT &ldA,
                CXXLAPACK_INT &info);

    void zpotrf(const char &uplo,
                const CXXLAPACK_INT &n,
                std::complex<double> *A, const CXXLAPACK_INT &ldA,
                CXXLAPACK_INT &info);
}

namespace LAPACK
{
    CXXLAPACK_INT potrf(const char &uplo,
                        const CXXLAPACK_INT &n,
                        float *A, const CXXLAPACK_INT &ldA)
    {
        CXXLAPACK_INT info;
        spotrf(uplo, n, A, ldA, info);
        return info;
    }

    CXXLAPACK_INT potrf(const char &uplo,
                        const CXXLAPACK_INT &n,
                        double *A, const CXXLAPACK_INT &ldA)
    {
        CXXLAPACK_INT info;
        dpotrf(uplo, n, A, ldA, info);
        return info;
    }

    CXXLAPACK_INT potrf(const char &uplo,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A, const CXXLAPACK_INT &ldA)
    {
        CXXLAPACK_INT info;
        cpotrf(uplo, n, A, ldA, info);
        return info;
    }

    CXXLAPACK_INT potrf(const char &uplo,
                        const CXXLAPACK_INT &n,
                        std::complex<double> *A, const CXXLAPACK_INT &ldA)
    {
        CXXLAPACK_INT info;
        zpotrf(uplo, n, A, ldA, info);
        return info;
    }
}
