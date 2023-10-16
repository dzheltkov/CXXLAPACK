#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define sormqr LAPACK_GLOBAL(sormqr,SORMQR)
#define dormqr LAPACK_GLOBAL(dormqr,DORMQR)
#define cunmqr LAPACK_GLOBAL(cunmqr,CUNMQR)
#define zunmqr LAPACK_GLOBAL(zunmqr,ZUNMQR)

extern "C"
{
    void sormqr(const char &side,
                const char &trans,
                const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &k,
                const float *A, const CXXLAPACK_INT &ldA,
                const float *tau,
                float *C, const CXXLAPACK_INT &ldC,
                float *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);

    void dormqr(const char &side,
                const char &trans,
                const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &k,
                const double *A, const CXXLAPACK_INT &ldA,
                const double *tau,
                double *C, const CXXLAPACK_INT &ldC,
                double *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);

    void cunmqr(const char &side,
                const char &trans,
                const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &k,
                const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                const std::complex<float> *tau,
                std::complex<float> *C, const CXXLAPACK_INT &ldC,
                std::complex<float> *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);

    void zunmqr(const char &side,
                const char &trans,
                const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                const CXXLAPACK_INT &k,
                const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                const std::complex<double> *tau,
                std::complex<double> *C, const CXXLAPACK_INT &ldC,
                std::complex<double> *work, const CXXLAPACK_INT &lwork,
                CXXLAPACK_INT &info);
}

namespace LAPACK
{
    CXXLAPACK_INT unmqr(const char &side,
                        const char &trans,
                        const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const float *A, const CXXLAPACK_INT &ldA,
                        const float *tau,
                        float *C, const CXXLAPACK_INT &ldC,
                        float *work, CXXLAPACK_INT lwork)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            float tmp;
            lwork = -1;
            sormqr(side, Trans, m, n, k, A, ldA, tau, C, ldC, &tmp, lwork, info);
            lwork = tmp;
            work = new float[lwork];
            to_free = true;
        }
        sormqr(side, Trans, m, n, k, A, ldA, tau, C, ldC, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }

    CXXLAPACK_INT unmqr(const char &side,
                        const char &trans,
                        const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const double *A, const CXXLAPACK_INT &ldA,
                        const double *tau,
                        double *C, const CXXLAPACK_INT &ldC,
                        double *work, CXXLAPACK_INT lwork)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            double tmp;
            lwork = -1;
            dormqr(side, Trans, m, n, k, A, ldA, tau, C, ldC, &tmp, lwork, info);
            lwork = tmp;
            work = new double[lwork];
            to_free = true;
        }
        dormqr(side, Trans, m, n, k, A, ldA, tau, C, ldC, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }

    CXXLAPACK_INT unmqr(const char &side,
                        const char &trans,
                        const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const std::complex<float> *A, const CXXLAPACK_INT &ldA,
                        const std::complex<float> *tau,
                        std::complex<float> *C, const CXXLAPACK_INT &ldC,
                        std::complex<float> *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            std::complex<float> tmp;
            lwork = -1;
            cunmqr(side, trans, m, n, k, A, ldA, tau, C, ldC, &tmp, lwork, info);
            lwork = std::real(tmp);
            work = new std::complex<float>[lwork];
            to_free = true;
        }
        cunmqr(side, trans, m, n, k, A, ldA, tau, C, ldC, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }

    CXXLAPACK_INT unmqr(const char &side,
                        const char &trans,
                        const CXXLAPACK_INT &m, const CXXLAPACK_INT &n,
                        const CXXLAPACK_INT &k,
                        const std::complex<double> *A, const CXXLAPACK_INT &ldA,
                        const std::complex<double> *tau,
                        std::complex<double> *C, const CXXLAPACK_INT &ldC,
                        std::complex<double> *work, CXXLAPACK_INT lwork)
    {
        CXXLAPACK_INT info;
        bool to_free = false;
        if (work == nullptr)
        {
            std::complex<double> tmp;
            lwork = -1;
            zunmqr(side, trans, m, n, k, A, ldA, tau, C, ldC, &tmp, lwork, info);
            lwork = std::real(tmp);
            work = new std::complex<double>[lwork];
            to_free = true;
        }
        zunmqr(side, trans, m, n, k, A, ldA, tau, C, ldC, work, lwork, info);
        if (to_free)
        {
            delete[] work;
        }
        return info;
    }
}
