#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define stptrs LAPACK_GLOBAL(stptrs,STPTRS)
#define dtptrs LAPACK_GLOBAL(dtptrs,DTPTRS)
#define ctptrs LAPACK_GLOBAL(ctptrs,CTPTRS)
#define ztptrs LAPACK_GLOBAL(ztptrs,ZTPTRS)

extern "C"
{
    void stptrs(const char &uplo,
                const char &transa,
                const char &diag,
                const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &nrhs,
                const float *AP,
                float *B, const CXXLAPACK_INT &ldB,
                CXXLAPACK_INT &info);

    void dtptrs(const char &uplo,
                const char &transa,
                const char &diag,
                const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &nrhs,
                const double *AP,
                double *B, const CXXLAPACK_INT &ldB,
                CXXLAPACK_INT &info);

    void ctptrs(const char &uplo,
                const char &transa,
                const char &diag,
                const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &nrhs,
                const std::complex<float> *AP,
                std::complex<float> *B, const CXXLAPACK_INT &ldB,
                CXXLAPACK_INT &info);

    void ztptrs(const char &uplo,
                const char &transa,
                const char &diag,
                const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &nrhs,
                const std::complex<double> *AP,
                std::complex<double> *B, const CXXLAPACK_INT &ldB,
                CXXLAPACK_INT &info);
}

namespace LAPACK
{
    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const float *AP,
                        float *B, const CXXLAPACK_INT &ldB)
    {
        CXXLAPACK_INT info;
        char Trans = transa;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        stptrs(uplo, Trans, diag, n, nrhs, AP, B, ldB, info);
        return info;
    }

    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const double *AP,
                        double *B, const CXXLAPACK_INT &ldB)
    {
        CXXLAPACK_INT info;
        char Trans = transa;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        dtptrs(uplo, Trans, diag, n, nrhs, AP, B, ldB, info);
        return info;
    }

    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const std::complex<float> *AP,
                        std::complex<float> *B, const CXXLAPACK_INT &ldB)
    {
        CXXLAPACK_INT info;
        ctptrs(uplo, transa, diag, n, nrhs, AP, B, ldB, info);
        return info;
    }

    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const std::complex<double> *AP,
                        std::complex<double> *B, const CXXLAPACK_INT &ldB)

    {
        CXXLAPACK_INT info;
        ztptrs(uplo, transa, diag, n, nrhs, AP, B, ldB, info);
        return info;
    }
}
