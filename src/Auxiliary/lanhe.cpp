#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

extern "C"
{
    void slanhe_stackreturn(float &r,
                            const char &Norm,
                            const char &UpperLower,
                            const CXXLAPACK_INT &n,
                            const float *A,
                            const CXXLAPACK_INT &ldA,
                            float *work);

    void dlanhe_stackreturn(double &r,
                            const char &Norm,
                            const char &UpperLower,
                            const CXXLAPACK_INT &n,
                            const double *A,
                            const CXXLAPACK_INT &ldA,
                            double *work);

    void clanhe_stackreturn(float &r,
                            const char &Norm,
                            const char &UpperLower,
                            const CXXLAPACK_INT &n,
                            const std::complex<float> *A,
                            const CXXLAPACK_INT &ldA,
                            float *work);


    void zlanhe_stackreturn(double &r,
                            const char &Norm,
                            const char &UpperLower,
                            const CXXLAPACK_INT &n,
                            const std::complex<double> *A,
                            const CXXLAPACK_INT &ldA,
                            double *work);
}

namespace LAPACK
{
    float lanhe(const char &Norm,
                const char &UpperLower,
                const CXXLAPACK_INT &n,
                const float *A,
                const CXXLAPACK_INT &ldA,
                float *work)
    {
        bool free_work = false;
        if (work == nullptr && (Norm == 'I' || Norm == 'i' ||
                                Norm == 'O' || Norm == 'o' || Norm == '1'))
        {
            work = new float[n];
            free_work = true;
        }

        float r;
        slanhe_stackreturn(r, Norm, UpperLower, n, A, ldA, work);

        if (free_work)
        {
            delete[] work;
        }

        return r;
    }

    double lanhe(const char &Norm,
                const char &UpperLower,
                const CXXLAPACK_INT &n,
                const double *A,
                const CXXLAPACK_INT &ldA,
                double *work)
    {
        bool free_work = false;
        if (work == nullptr && (Norm == 'I' || Norm == 'i' ||
                                Norm == 'O' || Norm == 'o' || Norm == '1'))
        {
            work = new double[n];
            free_work = true;
        }

        double r;
        dlanhe_stackreturn(r, Norm, UpperLower, n, A, ldA, work);

        if (free_work)
        {
            delete[] work;
        }

        return r;
    }

    float lanhe(const char &Norm,
                const char &UpperLower,
                const CXXLAPACK_INT &n,
                const std::complex<float> *A,
                const CXXLAPACK_INT &ldA,
                float *work)
    {
        bool free_work = false;
        if (work == nullptr && (Norm == 'I' || Norm == 'i' ||
                                Norm == 'O' || Norm == 'o' || Norm == '1'))
        {
            work = new float[n];
            free_work = true;
        }

        float r;
        clanhe_stackreturn(r, Norm, UpperLower, n, A, ldA, work);

        if (free_work)
        {
            delete[] work;
        }

        return r;
    }

    double lanhe(const char &Norm,
                const char &UpperLower,
                const CXXLAPACK_INT &n,
                const std::complex<double> *A,
                const CXXLAPACK_INT &ldA,
                double *work)
    {
        bool free_work = false;
        if (work == nullptr && (Norm == 'I' || Norm == 'i' ||
                                Norm == 'O' || Norm == 'o' || Norm == '1'))
        {
            work = new double[n];
            free_work = true;
        }

        double r;
        zlanhe_stackreturn(r, Norm, UpperLower, n, A, ldA, work);

        if (free_work)
        {
            delete[] work;
        }

        return r;
    }
}
