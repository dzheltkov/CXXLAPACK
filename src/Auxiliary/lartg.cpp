#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define slartg LAPACK_GLOBAL(slartg,SLARTG)
#define dlartg LAPACK_GLOBAL(dlartg,DLARTG)
#define clartg LAPACK_GLOBAL(clartg,CLARTG)
#define zlartg LAPACK_GLOBAL(zlartg,ZLARTG)

extern "C"
{
    void slartg(const float &a,
                const float &b,
                float &c,
                float &s,
                float &r);

    void dlartg(const double &a,
                const double &b,
                double &c,
                double &s,
                double &r);

    void clartg(const std::complex<float> &a,
                const std::complex<float> &b,
                float &c,
                std::complex<float> &s,
                std::complex<float> &r);

    void zlartg(const std::complex<double> &a,
                const std::complex<double> &b,
                double &c,
                std::complex<double> &s,
                std::complex<double> &r);
}

namespace LAPACK
{
    void lartg(const float &a,
               const float &b,
               float &c,
               float &s,
               float &r)
    {
        slartg(a, b, c, s, r);
    }

    void lartg(const double &a,
               const double &b,
               double &c,
               double &s,
               double &r)
    {
        dlartg(a, b, c, s, r);
    }

    void lartg(const std::complex<float> &a,
               const std::complex<float> &b,
               float &c,
               std::complex<float> &s,
               std::complex<float> &r)
    {
        clartg(a, b, c, s, r);
    }

    void lartg(const std::complex<double> &a,
               const std::complex<double> &b,
               double &c,
               std::complex<double> &s,
               std::complex<double> &r)
    {
        zlartg(a, b, c, s, r);
    }
}
