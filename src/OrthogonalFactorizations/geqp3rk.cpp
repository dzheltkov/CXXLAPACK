#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>
#include <iostream>
#define sgeqp3rk LAPACK_GLOBAL(sgeqp3rk,SGEQP3RK)
#define dgeqp3rk LAPACK_GLOBAL(dgeqp3rk,DGEQP3RK)
#define cgeqp3rk LAPACK_GLOBAL(cgeqp3rk,CGEQP3RK)
#define zgeqp3rk LAPACK_GLOBAL(zgeqp3rk,ZGEQP3RK)

extern "C"
{
    void sgeqp3rk(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                  const CXXLAPACK_INT &nrhs, const CXXLAPACK_INT &kmax,
                  const float &abstol, const float &reltol,
                  float *A, const CXXLAPACK_INT &LDA,
                  CXXLAPACK_INT &k,
                  float &maxc2nrmk, float &realmaxc2nrmk,
                  CXXLAPACK_INT *jpiv,
                  float *tau,
                  float *work, const CXXLAPACK_INT& lwork, CXXLAPACK_INT *iwork,
                  CXXLAPACK_INT &info);
    
    void dgeqp3rk(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                  const CXXLAPACK_INT &nrhs, const CXXLAPACK_INT &kmax,
                  const double &abstol, const double &reltol,
                  double *A, const CXXLAPACK_INT &LDA,
                  CXXLAPACK_INT &k,
                  double &maxc2nrmk, double &realmaxc2nrmk,
                  CXXLAPACK_INT *jpiv,
                  double *tau,
                  double *work, const CXXLAPACK_INT& lwork, CXXLAPACK_INT *iwork,
                  CXXLAPACK_INT &info);
    
    void cgeqp3rk(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                  const CXXLAPACK_INT &nrhs, const CXXLAPACK_INT &kmax,
                  const float &abstol, const float &reltol,
                  std::complex<float> *A, const CXXLAPACK_INT &LDA,
                  CXXLAPACK_INT &k,
                  float &maxc2nrmk, float &realmaxc2nrmk,
                  CXXLAPACK_INT *jpiv,
                  std::complex<float> *tau,
                  std::complex<float> *work, const CXXLAPACK_INT &lwork,
                  float* rwork, CXXLAPACK_INT *iwork,
                  CXXLAPACK_INT &info);
    
    void zgeqp3rk(const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                  const CXXLAPACK_INT &nrhs, const CXXLAPACK_INT &kmax,
                  const double &abstol, const double &reltol,
                  std::complex<double> *A, const CXXLAPACK_INT &LDA,
                  CXXLAPACK_INT &k,
                  double &maxc2nrmk, double &realmaxc2nrmk,
                  CXXLAPACK_INT *jpiv,
                  std::complex<double> *tau,
                  std::complex<double> *work, const CXXLAPACK_INT &lwork,
                  double* rwork, CXXLAPACK_INT *iwork,
                  CXXLAPACK_INT &info);
}

namespace LAPACK
{
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
                          float *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
     //   auto* rwork = new float[2 * n];
        auto* iwork = new CXXLAPACK_INT[n - 1];
        if (work == nullptr)
        {
            float tmp;
            lwork = -1;
            sgeqp3rk(m, n, nrhs, kmax, abstol, reltol, A, LDA, k, maxc2nrmk, realmaxc2nrmk, jpiv, tau, &tmp, lwork, iwork, info);
            lwork = tmp;
            work = new float[lwork];
            to_free = true;
        }
        sgeqp3rk(m, n, nrhs, kmax, abstol, reltol, A, LDA, k, maxc2nrmk, realmaxc2nrmk, jpiv, tau, work, lwork, iwork, info);
        for (auto* j = jpiv; j < jpiv + n; j++) {
            *j -= 1;
        }
        if (to_free)
        {
            delete[] work;
        }
    //    delete[] rwork;
        delete[] iwork;
        return info;
    }
    
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
                          double *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
    //    auto* rwork = new double[2 * n];
        auto* iwork = new CXXLAPACK_INT[n - 1];
        if (work == nullptr)
        {
            double tmp;
            lwork = -1;
            dgeqp3rk(m, n, nrhs, kmax, abstol, reltol, A, LDA, k, maxc2nrmk, realmaxc2nrmk, jpiv, tau, &tmp, lwork, iwork, info);
            lwork = tmp;
            work = new double[lwork];
            to_free = true;
        }
        dgeqp3rk(m, n, nrhs, kmax, abstol, reltol, A, LDA, k, maxc2nrmk, realmaxc2nrmk, jpiv, tau, work, lwork, iwork, info);
        for (auto* j = jpiv; j < jpiv + n; j++) {
            *j -= 1;
        }
        if (to_free)
        {
            delete[] work;
        }
      //  delete[] rwork;
        delete[] iwork;
        return info;
    }
    
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
                          std::complex<float> *work, CXXLAPACK_INT lwork)
    {
        std::cout << "HERE" << std::endl;
        CXXLAPACK_INT info;
        bool to_free = false;
        auto* rwork = new float[2 * n];
        auto* iwork = new CXXLAPACK_INT[n - 1];
        if (work == nullptr)
        {
            std::cout << "HERE 1" << std::endl;

            std::complex<float> tmp;
            lwork = -1;
            cgeqp3rk(m, n, nrhs, kmax, abstol, reltol, A, LDA, k, maxc2nrmk, realmaxc2nrmk, jpiv, tau, &tmp, lwork, rwork, iwork, info);
            lwork = std::real(tmp);
            std::cout << "lwork = " << lwork << std::endl;
            work = new std::complex<float>[lwork];
            to_free = true;
        }
        std::cout << m << ' ' << n << ' ' << LDA << ' ' << A[0] << ' ' << kmax << ' ' << abstol << ' ' << reltol << std::endl;
        int norm = 0;
        for (int i = 0; i < n * LDA; i++) {
            norm += std::abs(A[i]) * std::abs(A[i]);
        }
        std::cout << "norm = " << norm << std::endl;
        cgeqp3rk(m, n, nrhs, kmax, abstol, reltol, A, LDA, k, maxc2nrmk, realmaxc2nrmk, jpiv, tau, work, lwork, rwork, iwork, info);
        std::cout << "info = " << info << std::endl;
        std::cout << "maxc2nrmk" << maxc2nrmk << std::endl;
        std::cout << "k = " << k << std::endl;
        for (auto* j = jpiv; j < jpiv + n; j++) {
            *j -= 1;
        }
        if (to_free)
        {
            delete[] work;
        }
        delete[] rwork;
        delete[] iwork;
        return info;
    }
    
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
                          std::complex<double> *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        auto* rwork = new double[2 * n];
        auto* iwork = new CXXLAPACK_INT[n - 1];
        if (work == nullptr)
        {
            std::complex<double> tmp;
            lwork = -1;
            zgeqp3rk(m, n, nrhs, kmax, abstol, reltol, A, LDA, k, maxc2nrmk, realmaxc2nrmk, jpiv, tau, &tmp, lwork, rwork, iwork, info);
            lwork = std::real(tmp);
            work = new std::complex<double>[lwork];
            to_free = true;
        }
        zgeqp3rk(m, n, nrhs, kmax, abstol, reltol, A, LDA, k, maxc2nrmk, realmaxc2nrmk, jpiv, tau, work, lwork, rwork, iwork, info);
        for (auto* j = jpiv; j < jpiv + n; j++) {
            *j -= 1;
        }
        if (to_free)
        {
            delete[] work;
        }
        delete[] rwork;
        delete[] iwork;
        return info;
    }
}
