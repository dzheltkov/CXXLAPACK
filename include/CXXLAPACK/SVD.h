#ifndef CXXLAPACK_SVD_H
#define CXXLAPACK_SVD_H
namespace LAPACK
{
    // Float variants of LAPACK functions

    CXXLAPACK_INT gesdd(const char &jobz,
                        const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        float *A, const CXXLAPACK_INT &ldA,
                        float *s,
                        float *u, const CXXLAPACK_INT &ldu,
                        float *vt, const CXXLAPACK_INT &ldvt,
                        float *work, const CXXLAPACK_INT &lwork, float *rwork, int *iwork);

    // Double variants of LAPACK functions

    CXXLAPACK_INT gesdd(const char &jobz,
                        const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        double *A, const CXXLAPACK_INT &ldA,
                        double *s,
                        double *u, const CXXLAPACK_INT &ldu,
                        double *vt, const CXXLAPACK_INT &ldvt,
                        double *work, const CXXLAPACK_INT &lwork, double *rwork, int *iwork);

    // std::complex<float> variants of LAPACK functions

    CXXLAPACK_INT gesdd(const char &jobz,
                        const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        float *s,
                        std::complex<float> *u, const CXXLAPACK_INT &ldu,
                        std::complex<float> *vt, const CXXLAPACK_INT &ldvt,
                        std::complex<float> *work, const CXXLAPACK_INT &lwork, float *rwork, int *iwork);
                        
    CXXLAPACK_INT heevx(const char &jobz,
                        const char &range,
                        const char &uplo,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        const float &v1,
                        const float &vu,
                        const CXXLAPACK_INT &i1,
                        const CXXLAPACK_INT &iu,
                        const float &absto1,
                        float *w,
                        std::complex<float> *z, const CXXLAPACK_INT &ldz,
                        std::complex<float> *work, const CXXLAPACK_INT &lwork, float *rwork, int *iwork,
                        int *ifail);

    // std::complex<double> variants of LAPACK functions

    CXXLAPACK_INT gesdd(const char &jobz,
                        const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<double> *A, const CXXLAPACK_INT &ldA,
                        double *s,
                        std::complex<double> *u, const CXXLAPACK_INT &ldu,
                        std::complex<double> *vt, const CXXLAPACK_INT &ldvt,
                        std::complex<double> *work, const CXXLAPACK_INT &lwork, double *rwork, int *iwork);
                        
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
                        int *ifail);
}
#endif

