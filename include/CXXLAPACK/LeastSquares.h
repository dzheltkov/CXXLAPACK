#ifndef CXXLAPACK_LEASTSQUARES_H
#define CXXLAPACK_LEASTSQUARES_H
namespace LAPACK
{
    // Float variants of LAPACK functions

    CXXLAPACK_INT unmqr(const char &side,
                        const char &trans,
                        const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const float *A, const CXXLAPACK_INT &ldA,
                        const float *tau,
                        float *C, const CXXLAPACK_INT &ldC,
                        float *work = nullptr, CXXLAPACK_INT lwork = 0);




    // Double variants of LAPACK functions

    CXXLAPACK_INT unmqr(const char &side,
                        const char &trans,
                        const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const double *A, const CXXLAPACK_INT &ldA,
                        const double *tau,
                        double *C, const CXXLAPACK_INT &ldC,
                        double *work = nullptr, CXXLAPACK_INT lwork = 0);



    // std::complex<float> variants of LAPACK functions

    CXXLAPACK_INT unmqr(const char &side,
                        const char &trans,
                        const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        const std::complex<float> *tau,
                        std::complex<float> *C, const CXXLAPACK_INT &ldC,
                        std::complex<float> *work = nullptr, CXXLAPACK_INT lwork = 0);



    // std::complex<double> variants of LAPACK functions

    CXXLAPACK_INT unmqr(const char &side,
                        const char &trans,
                        const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                        const std::complex<double> *tau,
                        std::complex<double> *C, const CXXLAPACK_INT &ldC,
                        std::complex<double> *work = nullptr, CXXLAPACK_INT lwork = 0);
}
#endif

