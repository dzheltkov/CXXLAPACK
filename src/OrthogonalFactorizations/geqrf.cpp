#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define sgeqrf LAPACK_GLOBAL(sgeqrf,SGEQRF)
#define dgeqrf LAPACK_GLOBAL(dgeqrf,DGEQRF)
#define cgeqrf LAPACK_GLOBAL(cgeqrf,CGEQRF)
#define zgeqrf LAPACK_GLOBAL(zgeqrf,ZGEQRF)

extern "C"
{
    void sgeqrf(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                float *A, const CXXLAPACK_INT &ldA,
                float *tau,
                float *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);
    void dgeqrf(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                double *A, const CXXLAPACK_INT &ldA,
                double *tau,
                double *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);
    void cgeqrf(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                std::complex<float> *A, const CXXLAPACK_INT &ldA,
                std::complex<float> *tau,
                std::complex<float> *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);
    void zgeqrf(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                std::complex<double> *A, const CXXLAPACK_INT &ldA,
                std::complex<double> *tau,
                std::complex<double> *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);

}

namespace LAPACK
{
    CXXLAPACK_INT geqrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        float *A,
                        const CXXLAPACK_INT &LDA,
                        float *tau,
                        float *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            float tmp;
            lwork = -1;
            sgeqrf(m, n, A, LDA, tau, &tmp, lwork, info);
            lwork = tmp;
            work = new float[lwork];
            to_free = true;
        }
        sgeqrf(m, n, A, LDA, tau, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
    
    CXXLAPACK_INT geqrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        double *A,
                        const CXXLAPACK_INT &LDA,
                        double *tau,
                        double *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            double tmp;
            lwork = -1;
            dgeqrf(m, n, A, LDA, tau, &tmp, lwork, info);
            lwork = tmp;
            work = new double[lwork];
            to_free = true;
        }
        dgeqrf(m, n, A, LDA, tau, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
    
    CXXLAPACK_INT geqrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A,
                        const CXXLAPACK_INT &LDA,
                        std::complex<float> *tau,
                        std::complex<float> *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            std::complex<float> tmp;
            lwork = -1;
            cgeqrf(m, n, A, LDA, tau, &tmp, lwork, info);
            lwork = std::real(tmp);
            work = new std::complex<float>[lwork];
            to_free = true;
        }
        cgeqrf(m, n, A, LDA, tau, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
    
    CXXLAPACK_INT geqrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<double> *A,
                        const CXXLAPACK_INT &LDA,
                        std::complex<double> *tau,
                        std::complex<double> *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            std::complex<double> tmp;
            lwork = -1;
            zgeqrf(m, n, A, LDA, tau, &tmp, lwork, info);
            lwork = std::real(tmp);
            work = new std::complex<double>[lwork];
            to_free = true;
        }
        zgeqrf(m, n, A, LDA, tau, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
    
}
