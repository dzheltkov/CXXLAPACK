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




    // Double variants of LAPACK functions

    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const double *AP,
                        double *B, const CXXLAPACK_INT &ldB);



    // std::complex<float> variants of LAPACK functions

    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const std::complex<float> *AP,
                        std::complex<float> *B, const CXXLAPACK_INT &ldB);



    // std::complex<double> variants of LAPACK functions

    CXXLAPACK_INT tptrs(const char &uplo,
                        const char &transa,
                        const char &diag,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &nrhs,
                        const std::complex<double> *AP,
                        std::complex<double> *B, const CXXLAPACK_INT &ldB);
}
#endif

