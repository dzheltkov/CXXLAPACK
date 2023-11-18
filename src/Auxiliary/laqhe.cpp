#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define slaqhe LAPACK_GLOBAL(slaqsy,SLAQSY)
#define dlaqhe LAPACK_GLOBAL(dlaqsy,DLAQSY)
#define claqhe LAPACK_GLOBAL(claqhe,CLAQHE)
#define zlaqhe LAPACK_GLOBAL(zlaqhe,ZLAQHE)

extern "C"
{
    void slaqhe(const char &UpperLower,
                const CXXLAPACK_INT &n,
                float *A, const CXXLAPACK_INT &ldA,
                const float *s,
                const float &scond,
                const float &amax,
                char &Equed);

    void dlaqhe(const char &UpperLower,
                const CXXLAPACK_INT &n,
                double *A, const CXXLAPACK_INT &ldA,
                const double *s,
                const double &scond,
                const double &amax,
                char &Equed);

    void claqhe(const char &UpperLower,
                const CXXLAPACK_INT &n,
                std::complex<float> *A, const CXXLAPACK_INT &ldA,
                const float *s,
                const float &scond,
                const float &amax,
                char &Equed);

    void zlaqhe(const char &UpperLower,
                const CXXLAPACK_INT &n,
                std::complex<double> *A, const CXXLAPACK_INT &ldA,
                const double *s,
                const double &scond,
                const double &amax,
                char &Equed);
}

namespace LAPACK
{
    bool laqhe(const char &UpperLower,
               const CXXLAPACK_INT &n,
               float *A, const CXXLAPACK_INT &ldA,
               const float *s,
               const float &scond,
               const float &amax)
    {
        char equed = 'Y';
        slaqhe(UpperLower, n, A, ldA, s, scond, amax, equed);
        return (equed == 'Y');
    }

    bool laqhe(const char &UpperLower,
               const CXXLAPACK_INT &n,
               double *A, const CXXLAPACK_INT &ldA,
               const double *s,
               const double &scond,
               const double &amax)
    {
        char equed = 'Y';
        dlaqhe(UpperLower, n, A, ldA, s, scond, amax, equed);
        return (equed == 'Y');
    }

    bool laqhe(const char &UpperLower,
               const CXXLAPACK_INT &n,
               std::complex<float> *A, const CXXLAPACK_INT &ldA,
               const float *s,
               const float &scond,
               const float &amax)
    {
        char equed = 'Y';
        claqhe(UpperLower, n, A, ldA, s, scond, amax, equed);
        return (equed == 'Y');
    }

    bool laqhe(const char &UpperLower,
               const CXXLAPACK_INT &n,
               std::complex<double> *A, const CXXLAPACK_INT &ldA,
               const double *s,
               const double &scond,
               const double &amax)
    {
        char equed = 'Y';
        zlaqhe(UpperLower, n, A, ldA, s, scond, amax, equed);
        return (equed == 'Y');
    }
}
