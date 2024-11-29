#pragma once

namespace LAPACK
{
    // Float variants of LAPACK functions

    CXXLAPACK_INT geqrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        float *A,
                        const CXXLAPACK_INT &LDA,
                        float *tau,
                        float *work = nullptr, CXXLAPACK_INT lwork = 0);
    
    CXXLAPACK_INT ungqr(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const float *A,
                        const CXXLAPACK_INT &LDA,
                        const float *tau,
                        float *work = nullptr, CXXLAPACK_INT lwork = 0);
    
    CXXLAPACK_INT geqp3(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        float *A,
                        const CXXLAPACK_INT &LDA,
                        CXXLAPACK_INT *jpiv,
                        float *tau,
                        float *work = nullptr, CXXLAPACK_INT lwork = 0);
    
    CXXLAPACK_INT geqp3rk(const CXXLAPACK_INT &m,
                          const CXXLAPACK_INT &n,
                          const CXXLAPACK_INT &nrhs,
                          const CXXLAPACK_INT &kmax,
                          const float &abstol,
                          const float &reltol,
                          float *A,
                          const CXXLAPACK_INT &LDA,
                          CXXLAPACK_INT& k,
                          float &maxc2nrmk,
                          float &realmaxc2nrmk,
                          CXXLAPACK_INT *jpiv,
                          float *tau,
                          float *work = nullptr, CXXLAPACK_INT lwork = 0);


    // Double variants of LAPACK functions
    
    CXXLAPACK_INT geqrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        double *A,
                        const CXXLAPACK_INT &LDA,
                        double *tau,
                        double *work = nullptr, CXXLAPACK_INT lwork = 0);

    CXXLAPACK_INT ungqr(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const double *A,
                        const CXXLAPACK_INT &LDA,
                        const double *tau,
                        double *work = nullptr, CXXLAPACK_INT lwork = 0);
    
    CXXLAPACK_INT geqp3(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        double *A,
                        const CXXLAPACK_INT &LDA,
                        CXXLAPACK_INT *jpiv,
                        double *tau,
                        double *work = nullptr, CXXLAPACK_INT lwork = 0);
    
    CXXLAPACK_INT geqp3rk(const CXXLAPACK_INT &m,
                          const CXXLAPACK_INT &n,
                          const CXXLAPACK_INT &nrhs,
                          const CXXLAPACK_INT &kmax,
                          const double &abstol,
                          const double &reltol,
                          double *A,
                          const CXXLAPACK_INT &LDA,
                          CXXLAPACK_INT& k,
                          double &maxc2nrmk,
                          double &realmaxc2nrmk,
                          CXXLAPACK_INT *jpiv,
                          double *tau,
                          double *work = nullptr, CXXLAPACK_INT lwork = 0);
    


    // std::complex<float> variants of LAPACK functions
    
    CXXLAPACK_INT geqrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A,
                        const CXXLAPACK_INT &LDA,
                        std::complex<float> *tau,
                        std::complex<float> *work = nullptr, CXXLAPACK_INT lwork = 0);

    CXXLAPACK_INT ungqr(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const std::complex<float> *A,
                        const CXXLAPACK_INT &LDA,
                        const std::complex<float> *tau,
                        std::complex<float> *work = nullptr, CXXLAPACK_INT lwork = 0);
    
    CXXLAPACK_INT geqp3(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<float> *A,
                        const CXXLAPACK_INT &LDA,
                        CXXLAPACK_INT *jpiv,
                        std::complex<float> *tau,
                        std::complex<float> *work = nullptr, CXXLAPACK_INT lwork = 0);
    
    CXXLAPACK_INT geqp3rk(const CXXLAPACK_INT &m,
                          const CXXLAPACK_INT &n,
                          const CXXLAPACK_INT &nrhs,
                          const CXXLAPACK_INT &kmax,
                          const float &abstol,
                          const float &reltol,
                          std::complex<float> *A,
                          const CXXLAPACK_INT &LDA,
                          CXXLAPACK_INT& k,
                          float &maxc2nrmk,
                          float &realmaxc2nrmk,
                          CXXLAPACK_INT *jpiv,
                          std::complex<float> *tau,
                          std::complex<float> *work = nullptr, CXXLAPACK_INT lwork = 0);


    // std::complex<double> variants of LAPACK functions
    
    CXXLAPACK_INT geqrf(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<double> *A,
                        const CXXLAPACK_INT &LDA,
                        std::complex<double>* tau,
                        std::complex<double> *work = nullptr, CXXLAPACK_INT lwork = 0);

    CXXLAPACK_INT ungqr(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const std::complex<double> *A,
                        const CXXLAPACK_INT &LDA,
                        const std::complex<double>* tau,
                        std::complex<double> *work = nullptr, CXXLAPACK_INT lwork = 0);
    
    CXXLAPACK_INT geqp3(const CXXLAPACK_INT &m,
                        const CXXLAPACK_INT &n,
                        std::complex<double> *A,
                        const CXXLAPACK_INT &LDA,
                        CXXLAPACK_INT *jpiv,
                        std::complex<double> *tau,
                        std::complex<double> *work = nullptr, CXXLAPACK_INT lwork = 0);
    
    CXXLAPACK_INT geqp3rk(const CXXLAPACK_INT &m,
                          const CXXLAPACK_INT &n,
                          const CXXLAPACK_INT &nrhs,
                          const CXXLAPACK_INT &kmax,
                          const double &abstol,
                          const double &reltol,
                          std::complex<double> *A,
                          const CXXLAPACK_INT &LDA,
                          CXXLAPACK_INT& k,
                          double &maxc2nrmk,
                          double &realmaxc2nrmk,
                          CXXLAPACK_INT *jpiv,
                          std::complex<double> *tau,
                          std::complex<double> *work = nullptr, CXXLAPACK_INT lwork = 0);
}
