#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define sgesdd LAPACK_GLOBAL(sgesdd,SGESDD)
#define dgesdd LAPACK_GLOBAL(dgesdd,DGESDD)
#define cgesdd LAPACK_GLOBAL(cgesdd,CGESDD)
#define zgesdd LAPACK_GLOBAL(zgesdd,ZGESDD)

extern "C"
{
    void sgesdd(const char &jobz,
                const CXXLAPACK_INT &m,
                const CXXLAPACK_INT &n,
                float *A, const CXXLAPACK_INT &ldA,
                float *s,
                float *u, const CXXLAPACK_INT &ldu,
                float *vt, const CXXLAPACK_INT &ldvt,
                float *work, const CXXLAPACK_INT &lwork, float *rwork, int *iwork,
                CXXLAPACK_INT &info);

    void dgesdd(const char &jobz,
                const CXXLAPACK_INT &m,
                const CXXLAPACK_INT &n,
                double *A, const CXXLAPACK_INT &ldA,
                double *s,
                double *u, const CXXLAPACK_INT &ldu,
                double *vt, const CXXLAPACK_INT &ldvt,
                double *work, const CXXLAPACK_INT &lwork, double *rwork, int *iwork,
                CXXLAPACK_INT &info);
                
    void cgesdd(const char &jobz,
                const CXXLAPACK_INT &m,
                const CXXLAPACK_INT &n,
                std::complex<float> *A, const CXXLAPACK_INT &ldA,
                float *s,
                std::complex<float> *u, const CXXLAPACK_INT &ldu,
                std::complex<float> *vt, const CXXLAPACK_INT &ldvt,
                std::complex<float> *work, const CXXLAPACK_INT &lwork, float *rwork, int *iwork,
                CXXLAPACK_INT &info);
                
    void zgesdd(const char &jobz,
                const CXXLAPACK_INT &m,
                const CXXLAPACK_INT &n,
                std::complex<double> *A, const CXXLAPACK_INT &ldA,
                double *s,
                std::complex<double> *u, const CXXLAPACK_INT &ldu,
                std::complex<double> *vt, const CXXLAPACK_INT &ldvt,
                std::complex<double> *work, const CXXLAPACK_INT &lwork, double *rwork, int *iwork,
                CXXLAPACK_INT &info);
}

namespace LAPACK
{
    CXXLAPACK_INT gesdd(const char &jobz,
                        const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        float *A, const CXXLAPACK_INT &ldA,
                        float *s,
                        float *u, const CXXLAPACK_INT &ldu,
                        float *vt, const CXXLAPACK_INT &ldvt,
                        float *work, const CXXLAPACK_INT &lwork, float *rwork, int *iwork)
    {
        CXXLAPACK_INT info;
        sgesdd(jobz, m ,n, A, ldA, s, u, ldu, vt, ldvt, work, lwork, rwork, iwork, info);
        return info;
    }

    CXXLAPACK_INT gesdd(const char &jobz,
                        const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        double *A, const CXXLAPACK_INT &ldA,
                        double *s,
                        double *u, const CXXLAPACK_INT &ldu,
                        double *vt, const CXXLAPACK_INT &ldvt,
                        double *work, const CXXLAPACK_INT &lwork, double *rwork, int *iwork)
    {
        CXXLAPACK_INT info;
        dgesdd(jobz, m ,n, A, ldA, s, u, ldu, vt, ldvt, work, lwork, rwork, iwork, info);
        return info;
    }

    CXXLAPACK_INT gesdd(const char &jobz,
                        const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        float *s,
                        std::complex<float> *u, const CXXLAPACK_INT &ldu,
                        std::complex<float> *vt, const CXXLAPACK_INT &ldvt,
                        std::complex<float> *work, const CXXLAPACK_INT &lwork, float *rwork, int *iwork)
    {
        CXXLAPACK_INT info;
        cgesdd(jobz, m ,n, A, ldA, s, u, ldu, vt, ldvt, work, lwork, rwork, iwork, info);
        return info;
    }

    CXXLAPACK_INT gesdd(const char &jobz,
                        const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<double> *A, const CXXLAPACK_INT &ldA,
                        double *s,
                        std::complex<double> *u, const CXXLAPACK_INT &ldu,
                        std::complex<double> *vt, const CXXLAPACK_INT &ldvt,
                        std::complex<double> *work, const CXXLAPACK_INT &lwork, double *rwork, int *iwork)
    {
        CXXLAPACK_INT info;
        zgesdd(jobz, m ,n, A, ldA, s, u, ldu, vt, ldvt, work, lwork, rwork, iwork, info);
        return info;
    }
}
