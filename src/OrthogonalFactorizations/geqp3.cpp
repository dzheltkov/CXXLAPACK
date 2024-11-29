#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>
#include <iostream>
#define sgeqp3 LAPACK_GLOBAL(sgeqp3,SGEQP3)
#define dgeqp3 LAPACK_GLOBAL(dgeqp3,DGEQP3)
#define cgeqp3 LAPACK_GLOBAL(cgeqp3,CGEQP3)
#define zgeqp3 LAPACK_GLOBAL(zgeqp3,ZGEQP3)

extern "C"
{
    void sgeqp3(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                float *A, const CXXLAPACK_INT &LDA,
                CXXLAPACK_INT *jpiv,
                float *tau,
                float *work, const CXXLAPACK_INT& lwork,
                CXXLAPACK_INT &info);
    
    void dgeqp3(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                double *A, const CXXLAPACK_INT &LDA,
                CXXLAPACK_INT *jpiv,
                double *tau,
                double *work, const CXXLAPACK_INT& lwork,
                CXXLAPACK_INT &info);
    
    void cgeqp3(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                std::complex<float> *A, const CXXLAPACK_INT &LDA,
                CXXLAPACK_INT *jpiv,
                std::complex<float> *tau,
                std::complex<float> *work, const CXXLAPACK_INT &lwork,
                float* rwork,
                CXXLAPACK_INT &info);
    
    void zgeqp3(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                std::complex<double> *A, const CXXLAPACK_INT &LDA,
                CXXLAPACK_INT *jpiv,
                std::complex<double> *tau,
                std::complex<double> *work, const CXXLAPACK_INT &lwork,
                double* rwork,
                CXXLAPACK_INT &info);
}

namespace LAPACK
{
    CXXLAPACK_INT geqp3(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        float *A,
                        const CXXLAPACK_INT &LDA,
                        CXXLAPACK_INT *jpiv,
                        float *tau,
                        float *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            float tmp;
            lwork = -1;
            sgeqp3(m, n, A, LDA, jpiv, tau, &tmp, lwork, info);
            lwork = tmp;
            work = new float[lwork];
            to_free = true;
        }
        sgeqp3(m, n, A, LDA, jpiv, tau, work, lwork, info);
        for (auto* j = jpiv; j < jpiv + n; j++) {
            *j -= 1;
        }
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
    
    CXXLAPACK_INT geqp3(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        double *A,
                        const CXXLAPACK_INT &LDA,
                        CXXLAPACK_INT *jpiv,
                        double *tau,
                        double *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            double tmp;
            lwork = -1;
            dgeqp3(m, n, A, LDA, jpiv, tau, &tmp, lwork, info);
            lwork = tmp;
            work = new double[lwork];
            to_free = true;
        }
        dgeqp3(m, n, A, LDA, jpiv, tau, work, lwork, info);
        for (auto* j = jpiv; j < jpiv + n; j++) {
            *j -= 1;
        }
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
    
    CXXLAPACK_INT geqp3(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A,
                        const CXXLAPACK_INT &LDA,
                        CXXLAPACK_INT *jpiv,
                        std::complex<float> *tau,
                        std::complex<float> *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        auto* rwork = new float[2 * n];
        if (work == nullptr)
        {
            std::complex<float> tmp;
            lwork = -1;
            cgeqp3(m, n, A, LDA, jpiv, tau, &tmp, lwork, rwork, info);
            lwork = std::real(tmp);
            work = new std::complex<float>[lwork];
            to_free = true;
        }
        cgeqp3(m, n, A, LDA, jpiv, tau, work, lwork, rwork, info);
        for (auto* j = jpiv; j < jpiv + n; j++) {
            *j -= 1;
        }
        if (to_free)
        {
            delete[] work;
        }
        delete[] rwork;
        return info;
    }
    
    CXXLAPACK_INT geqp3(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<double> *A,
                        const CXXLAPACK_INT &LDA,
                        CXXLAPACK_INT *jpiv,
                        std::complex<double> *tau,
                        std::complex<double> *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        auto* rwork = new double[2 * n];
        if (work == nullptr)
        {
            std::complex<double> tmp;
            lwork = -1;
            zgeqp3(m, n, A, LDA, jpiv, tau, &tmp, lwork, rwork, info);
            lwork = std::real(tmp);
            work = new std::complex<double>[lwork];
            to_free = true;
        }
        zgeqp3(m, n, A, LDA, jpiv, tau, work, lwork, rwork, info);
        for (auto* j = jpiv; j < jpiv + n; j++) {
            *j -= 1;
        }
        if (to_free)
        {
            delete[] work;
        }
        delete[] rwork;
        return info;
    }
    
}
