#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define spoequ LAPACK_GLOBAL(spoequ,SPOEQU)
#define dpoequ LAPACK_GLOBAL(dpoequ,DPOEQU)
#define cpoequ LAPACK_GLOBAL(cpoequ,CPOEQU)
#define zpoequ LAPACK_GLOBAL(zpoequ,ZPOEQU)

extern "C"
{
    void spoequ(const CXXLAPACK_INT &n,
                const float *A, const CXXLAPACK_INT &ldA,
                float *s,
                float &scond,
                float &amax,
                CXXLAPACK_INT &info);

    void dpoequ(const CXXLAPACK_INT &n,
                const double *A, const CXXLAPACK_INT &ldA,
                double *s,
                double &scond,
                double &amax,
                CXXLAPACK_INT &info);

    void cpoequ(const CXXLAPACK_INT &n,
                const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                float *s,
                float &scond,
                float &amax,
                CXXLAPACK_INT &info);

    void zpoequ(const CXXLAPACK_INT &n,
                const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                double *s,
                double &scond,
                double &amax,
                CXXLAPACK_INT &info);
}

namespace LAPACK
{

    CXXLAPACK_INT poequ(const CXXLAPACK_INT &n,
                        const float *A, const CXXLAPACK_INT &ldA,
                        float *s,
                        float &scond,
                        float &amax)
    {
        CXXLAPACK_INT info;
        spoequ(n, A, ldA, s, scond, amax, info);
        return info;
    }

    CXXLAPACK_INT poequ(const CXXLAPACK_INT &n,
                        const double *A, const CXXLAPACK_INT &ldA,
                        double *s,
                        double &scond,
                        double &amax)
    {
        CXXLAPACK_INT info;
        dpoequ(n, A, ldA, s, scond, amax, info);
        return info;
    }

    CXXLAPACK_INT poequ(const CXXLAPACK_INT &n,
                        const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        float *s,
                        float &scond,
                        float &amax)
    {
        CXXLAPACK_INT info;
        cpoequ(n, A, ldA, s, scond, amax, info);
        return info;
    }

    CXXLAPACK_INT poequ(const CXXLAPACK_INT &n,
                        const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                        double *s,
                        double &scond,
                        double &amax)
    {
        CXXLAPACK_INT info;
        zpoequ(n, A, ldA, s, scond, amax, info);
        return info;
    }
}
