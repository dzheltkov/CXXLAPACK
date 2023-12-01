#ifndef CXXLAPACK_AUXILIARY_H
#define CXXLAPACK_AUXILIARY_H
namespace LAPACK
{
    // Float variants of LAPACK functions

    void lacgv(const CXXLAPACK_INT &n,
               float *x,
               const CXXLAPACK_INT &incx);

    void larfg(const CXXLAPACK_INT &n,
               float &alpha,
               float *x,
               const CXXLAPACK_INT &incx,
               float &tau);

    void lartg(const float &a,
               const float &b,
               float &c,
               float &s,
               float &r);

    float lanhe(const char &Norm,
                const char &UpperLower,
                const CXXLAPACK_INT &n,
                float *A,
                const CXXLAPACK_INT &ldA,
                float *work = nullptr);

    bool laqhe(const char &UpperLower,
               const CXXLAPACK_INT& n,
               float *A, const CXXLAPACK_INT&ldA,
               const float *s,
               const float &scond,
               const float &amax);





    // Double variants of LAPACK functions

    void lacgv(const CXXLAPACK_INT &n,
               double *x,
               const CXXLAPACK_INT &incx);

    void larfg(const CXXLAPACK_INT &n,
               double &alpha,
               double *x,
               const CXXLAPACK_INT &incx,
               double &tau);

    void lartg(const double &a,
               const double &b,
               double &c,
               double &s,
               double &r);

    double lanhe(const char &Norm,
                const char &UpperLower,
                const CXXLAPACK_INT &n,
                double *A,
                const CXXLAPACK_INT &ldA,
                double *work = nullptr);

    bool laqhe(const char &UpperLower,
               const CXXLAPACK_INT& n,
               double *A, const CXXLAPACK_INT&ldA,
               const double *s,
               const double &scond,
               const double &amax);


    // std::complex<float> variants of LAPACK functions

    void lacgv(const CXXLAPACK_INT &n,
               std::complex<float> *x,
               const CXXLAPACK_INT &incx);

    void larfg(const CXXLAPACK_INT &n,
               std::complex<float> &alpha,
               std::complex<float> *x,
               const CXXLAPACK_INT &incx,
               std::complex<float> &tau);

    void lartg(const std::complex<float> &a,
               const std::complex<float> &b,
               float &c,
               std::complex<float> &s,
               std::complex<float> &r);

    float lanhe(const char &Norm,
                const char &UpperLower,
                const CXXLAPACK_INT &n,
                std::complex<float> *A,
                const CXXLAPACK_INT &ldA,
                float *work = nullptr);

    bool laqhe(const char &UpperLower,
               const CXXLAPACK_INT& n,
               std::complex<float> *A, const CXXLAPACK_INT&ldA,
               const float *s,
               const float &scond,
               const float &amax);



    // std::complex<double> variants of LAPACK functions

    void lacgv(const CXXLAPACK_INT &n,
               std::complex<double> *x,
               const CXXLAPACK_INT &incx);

    void larfg(const CXXLAPACK_INT &n,
               std::complex<double> &alpha,
               std::complex<double> *x,
               const CXXLAPACK_INT &incx,
               std::complex<double> &tau);

    void lartg(const std::complex<double> &a,
               const std::complex<double> &b,
               double &c,
               std::complex<double> &s,
               std::complex<double> &r);

    double lanhe(const char &Norm,
                 const char &UpperLower,
                 const CXXLAPACK_INT &n,
                 std::complex<double> *A,
                 const CXXLAPACK_INT &ldA,
                 double *work = nullptr);

    bool laqhe(const char &UpperLower,
               const CXXLAPACK_INT& n,
               std::complex<double> *A, const CXXLAPACK_INT&ldA,
               const double *s,
               const double &scond,
               const double &amax);
}
#endif

