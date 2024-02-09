#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define cheevx LAPACK_GLOBAL(cheevx,SGESDD)
#define zheevx LAPACK_GLOBAL(zheevx,DGESDD)

extern "C"
{        
    void cheevx(const char &jobz,
                const char &range,
                const char &uplo,
                const CXXLAPACK_INT &n,
                std::complex<float> *A, const CXXLAPACK_INT &ldA,
                const float &vl,
                const float &vu,
                const CXXLAPACK_INT &i1,
                const CXXLAPACK_INT &iu,
                const float &absto1,
                CXXLAPACK_INT &m,
                float *w,
                std::complex<float> *z, const CXXLAPACK_INT &ldz,
                std::complex<float> *work, const CXXLAPACK_INT &lwork, float *rwork, int *iwork,
                int *ifail, CXXLAPACK_INT &info);
                
    void zheevx(const char &jobz,
                const char &range,
                const char &uplo,
                const CXXLAPACK_INT &n,
                std::complex<double> *A, const CXXLAPACK_INT &ldA,
                const double &vl,
                const double &vu,
                const CXXLAPACK_INT &i1,
                const CXXLAPACK_INT &iu,
                const double &absto1,
                CXXLAPACK_INT &m,
                double *w,
                std::complex<double> *z, const CXXLAPACK_INT &ldz,
                std::complex<double> *work, const CXXLAPACK_INT &lwork, double *rwork, int *iwork,
                int *ifail, CXXLAPACK_INT &info);
}

namespace LAPACK
{
    CXXLAPACK_INT heevx(const char &jobz,
                        const char &range,
                        const char &uplo,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        const float &vl,
                        const float &vu,
                        const CXXLAPACK_INT &i1,
                        const CXXLAPACK_INT &iu,
                        const float &absto1,
                        float *w,
                        std::complex<float> *z, const CXXLAPACK_INT &ldz,
                        std::complex<float> *work, const CXXLAPACK_INT &lwork, float *rwork, int *iwork,
                        int *ifail)
    {
        CXXLAPACK_INT info;
        CXXLAPACK_INT m;
        cheevx(jobz, range, uplo, n, A, ldA, vl, vu, i1, iu, absto1, m, w, z, ldz, work, lwork, rwork, iwork, ifail, info);
        return info;
    }

    CXXLAPACK_INT heevx(const char &jobz,
                        const char &range,
                        const char &uplo,
                        const CXXLAPACK_INT &n,
                        std::complex<double> *A, const CXXLAPACK_INT &ldA,
                        const double &vl,
                        const double &vu,
                        const CXXLAPACK_INT &i1,
                        const CXXLAPACK_INT &iu,
                        const double &absto1,
                        double *w,
                        std::complex<double> *z, const CXXLAPACK_INT &ldz,
                        std::complex<double> *work, const CXXLAPACK_INT &lwork, double *rwork, int *iwork,
                        int *ifail)
    {
        CXXLAPACK_INT info;
        CXXLAPACK_INT m;
        zheevx(jobz, range, uplo, n, A, ldA, vl, vu, i1, iu, absto1, m, w, z, ldz, work, lwork, rwork, iwork, ifail, info);
        return info;
    }
}
