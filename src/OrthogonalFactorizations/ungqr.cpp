#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define sorgqr LAPACK_GLOBAL(sorgqr,SORGQR)
#define dorgqr LAPACK_GLOBAL(dorgqr,DORGQR)
#define cungqr LAPACK_GLOBAL(cungqr,CUNGQR)
#define zungqr LAPACK_GLOBAL(zungqr,ZUNGQR)

extern "C"
{
    void sorgqr(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n, const CXXLAPACK_INT &k,
                const float *A, const CXXLAPACK_INT &ldA,
                const float *tau,
                float *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);
    void dorgqr(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n, const CXXLAPACK_INT &k,
                const double *A, const CXXLAPACK_INT &ldA,
                const double *tau,
                double *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);
    void cungqr(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n, const CXXLAPACK_INT &k,
                const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                const std::complex<float> *tau,
                std::complex<float> *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);
    void zungqr(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n, const CXXLAPACK_INT &k,
                const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                const std::complex<double> *tau,
                std::complex<double> *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);

}

namespace LAPACK
{
    CXXLAPACK_INT ungqr(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const float *A,
                        const CXXLAPACK_INT &LDA,
                        const float *tau,
                        float *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            float tmp;
            lwork = -1;
            sorgqr(m, n, k, A, LDA, tau, &tmp, lwork, info);
            lwork = tmp;
            work = new float[lwork];
            to_free = true;
        }
        sorgqr(m, n, k, A, LDA, tau, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
    
    CXXLAPACK_INT ungqr(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const double *A,
                        const CXXLAPACK_INT &LDA,
                        const double *tau,
                        double *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            double tmp;
            lwork = -1;
            dorgqr(m, n, k, A, LDA, tau, &tmp, lwork, info);
            lwork = tmp;
            work = new double[lwork];
            to_free = true;
        }
        dorgqr(m, n, k, A, LDA, tau, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
    
    CXXLAPACK_INT ungqr(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const std::complex<float> *A,
                        const CXXLAPACK_INT &LDA,
                        const std::complex<float> *tau,
                        std::complex<float> *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            std::complex<float> tmp;
            lwork = -1;
            cungqr(m, n, k, A, LDA, tau, &tmp, lwork, info);
            lwork = std::real(tmp);
            work = new std::complex<float>[lwork];
            to_free = true;
        }
        cungqr(m, n, k, A, LDA, tau, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
    
    CXXLAPACK_INT ungqr(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const std::complex<double> *A,
                        const CXXLAPACK_INT &LDA,
                        const std::complex<double> *tau,
                        std::complex<double> *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            std::complex<double> tmp;
            lwork = -1;
            zungqr(m, n, k, A, LDA, tau, &tmp, lwork, info);
            lwork = std::real(tmp);
            work = new std::complex<double>[lwork];
            to_free = true;
        }
        zungqr(m, n, k, A, LDA, tau, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
}
