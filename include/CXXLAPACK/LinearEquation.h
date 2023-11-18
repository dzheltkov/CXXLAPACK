#ifndef CXXLAPACK_LINEAREQUATION_H
#define CXXLAPACK_LINEAREQUATION_H
namespace LAPACK
{
    // Float variants of LAPACK functions

    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const float *AP,
                        float *B, const CXXLAPACK_INT &ldB);

    CXXLAPACK_INT potrf(const char &uplo,
                        const CXXLAPACK_INT &n,
                        float *A, const CXXLAPACK_INT &ldA);

    CXXLAPACK_INT poequ(const CXXLAPACK_INT &n,
                        const float *A, const CXXLAPACK_INT &ldA,
                        float *s,
                        float &scond,
                        float &amax);

    CXXLAPACK_INT poequb(const CXXLAPACK_INT &n,
                         const float *A, const CXXLAPACK_INT &ldA,
                         float *s,
                         float &scond,
                         float &amax);




    // Double variants of LAPACK functions

    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const double *AP,
                        double *B, const CXXLAPACK_INT &ldB);

    CXXLAPACK_INT potrf(const char &uplo,
                        const CXXLAPACK_INT &n,
                        double *A, const CXXLAPACK_INT &ldA);

    CXXLAPACK_INT poequ(const CXXLAPACK_INT &n,
                        const double *A, const CXXLAPACK_INT &ldA,
                        double *s,
                        double &scond,
                        double &amax);

    CXXLAPACK_INT poequb(const CXXLAPACK_INT &n,
                         const double *A, const CXXLAPACK_INT &ldA,
                         double *s,
                         double &scond,
                         double &amax);



    // std::complex<float> variants of LAPACK functions

    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const std::complex<float> *AP,
                        std::complex<float> *B, const CXXLAPACK_INT &ldB);

    CXXLAPACK_INT potrf(const char &uplo,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A, const CXXLAPACK_INT &ldA);

    CXXLAPACK_INT poequ(const CXXLAPACK_INT &n,
                        const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        float *s,
                        float &scond,
                        float &amax);

    CXXLAPACK_INT poequb(const CXXLAPACK_INT &n,
                         const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                         float *s,
                         float &scond,
                         float &amax);



    // std::complex<double> variants of LAPACK functions

    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const std::complex<double> *AP,
                        std::complex<double> *B, const CXXLAPACK_INT &ldB);

    CXXLAPACK_INT potrf(const char &uplo,
                        const CXXLAPACK_INT &n,
                        std::complex<double> *A, const CXXLAPACK_INT &ldA);

    CXXLAPACK_INT poequ(const CXXLAPACK_INT &n,
                        const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                        double *s,
                        double &scond,
                        double &amax);

    CXXLAPACK_INT poequb(const CXXLAPACK_INT &n,
                         const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                         double *s,
                         double &scond,
                         double &amax);
}
#endif

