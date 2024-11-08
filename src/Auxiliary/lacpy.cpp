#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define slacpy LAPACK_GLOBAL(slacpy,SLACPY)
#define dlacpy LAPACK_GLOBAL(dlacpy,DLACPY)
#define clacpy LAPACK_GLOBAL(clacpy,CLACPY)
#define zlacpy LAPACK_GLOBAL(zlacpy,ZLACPY)

extern "C"
{
    void slacpy(const char &UPLO,
               const CXXLAPACK_INT &m,
               const CXXLAPACK_INT &n,
               const float *A,
               const CXXLAPACK_INT &ldA,
               float* B,
               const CXXLAPACK_INT &ldB);
    
    void dlacpy(const char &UPLO,
               const CXXLAPACK_INT &m,
               const CXXLAPACK_INT &n,
               const double *A,
               const CXXLAPACK_INT &ldA,
               double* B,
               const CXXLAPACK_INT &ldB);
    
    void clacpy(const char &UPLO,
               const CXXLAPACK_INT &m,
               const CXXLAPACK_INT &n,
               const std::complex<float> *A,
               const CXXLAPACK_INT &ldA,
               std::complex<float>* B,
               const CXXLAPACK_INT &ldB);
    
    void zlacpy(const char &UPLO,
               const CXXLAPACK_INT &m,
               const CXXLAPACK_INT &n,
               const std::complex<double> *A,
               const CXXLAPACK_INT &ldA,
               std::complex<double>* B,
               const CXXLAPACK_INT &ldB);

}

namespace LAPACK
{
    void lacpy(const char &UPLO,
               const CXXLAPACK_INT &m,
               const CXXLAPACK_INT &n,
               const float *A,
               const CXXLAPACK_INT &ldA,
               float* B,
               const CXXLAPACK_INT &ldB)
    {
        slacpy(UPLO, m, n, A, ldA, B, ldB);
    }

    void lacpy(const char &UPLO,
               const CXXLAPACK_INT &m,
               const CXXLAPACK_INT &n,
               const double *A,
               const CXXLAPACK_INT &ldA,
               double* B,
               const CXXLAPACK_INT &ldB)
    {
        dlacpy(UPLO, m, n, A, ldA, B, ldB);
    }

    void lacpy(const char &UPLO,
               const CXXLAPACK_INT &m,
               const CXXLAPACK_INT &n,
               const std::complex<float> *A,
               const CXXLAPACK_INT &ldA,
               std::complex<float>* B,
               const CXXLAPACK_INT &ldB)
    {
        clacpy(UPLO, m, n, A, ldA, B, ldB);
    }
    
    void lacpy(const char &UPLO,
               const CXXLAPACK_INT &m,
               const CXXLAPACK_INT &n,
               const std::complex<double> *A,
               const CXXLAPACK_INT &ldA,
               std::complex<double>* B,
               const CXXLAPACK_INT &ldB)
    {
        zlacpy(UPLO, m, n, A, ldA, B, ldB);
    }
}
