#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define spoequb LAPACK_GLOBAL(spoequb,SPOEQUB)
#define dpoequb LAPACK_GLOBAL(dpoequb,DPOEQUB)
#define cpoequb LAPACK_GLOBAL(cpoequb,CPOEQUB)
#define zpoequb LAPACK_GLOBAL(zpoequb,ZPOEQUB)

extern "C"
{
    void spoequb(const CXXLAPACK_INT &n,
                const float *A, const CXXLAPACK_INT &ldA,
                float *s,
                float &scond,
                float &amax,
                CXXLAPACK_INT &info);

    void dpoequb(const CXXLAPACK_INT &n,
                const double *A, const CXXLAPACK_INT &ldA,
                double *s,
                double &scond,
                double &amax,
                CXXLAPACK_INT &info);

    void cpoequb(const CXXLAPACK_INT &n,
                const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                float *s,
                float &scond,
                float &amax,
                CXXLAPACK_INT &info);

    void zpoequb(const CXXLAPACK_INT &n,
                const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                double *s,
                double &scond,
                double &amax,
                CXXLAPACK_INT &info);
}

namespace LAPACK
{

    CXXLAPACK_INT poequb(const CXXLAPACK_INT &n,
                        const float *A, const CXXLAPACK_INT &ldA,
                        float *s,
                        float &scond,
                        float &amax)
    {
        CXXLAPACK_INT info;
        spoequb(n, A, ldA, s, scond, amax, info);
        return info;
    }

    CXXLAPACK_INT poequb(const CXXLAPACK_INT &n,
                        const double *A, const CXXLAPACK_INT &ldA,
                        double *s,
                        double &scond,
                        double &amax)
    {
        CXXLAPACK_INT info;
        dpoequb(n, A, ldA, s, scond, amax, info);
        return info;
    }

    CXXLAPACK_INT poequb(const CXXLAPACK_INT &n,
                        const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        float *s,
                        float &scond,
                        float &amax)
    {
        CXXLAPACK_INT info;
        cpoequb(n, A, ldA, s, scond, amax, info);
        return info;
    }

    CXXLAPACK_INT poequb(const CXXLAPACK_INT &n,
                        const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                        double *s,
                        double &scond,
                        double &amax)
    {
        CXXLAPACK_INT info;
        zpoequb(n, A, ldA, s, scond, amax, info);
        return info;
    }
}
