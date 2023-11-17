#include <LAPACKFortranMangle.h>
#include <CXXLAPACK_config.h>
#include <complex>

#define slanhe LAPACK_GLOBAL(slansy,SLANSY)
#define dlanhe LAPACK_GLOBAL(dlansy,DLANSY)
#define clanhe LAPACK_GLOBAL(clanhe,CLANHE)
#define zlanhe LAPACK_GLOBAL(zlanhe,ZLANHE)

extern "C"
{
    float slanhe(const char &Norm,
                 const char &UpperLower,
                 const CXXLAPACK_INT &n,
                 const float *A,
                 const CXXLAPACK_INT &ldA,
                 float *work);

    double dlanhe(const char &Norm,
                 const char &UpperLower,
                 const CXXLAPACK_INT &n,
                 const double *A,
                 const CXXLAPACK_INT &ldA,
                 double *work);

    float clanhe(const char &Norm,
                 const char &UpperLower,
                 const CXXLAPACK_INT &n,
                 const std::complex<float> *A,
                 const CXXLAPACK_INT &ldA,
                 float *work);


    double zlanhe(const char &Norm,
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

        float r = slanhe(Norm, UpperLower, n, A, ldA, work);

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

        double r = dlanhe(Norm, UpperLower, n, A, ldA, work);

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

        float r = clanhe(Norm, UpperLower, n, A, ldA, work);

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

        double r = zlanhe(Norm, UpperLower, n, A, ldA, work);

        if (free_work)
        {
            delete[] work;
        }

        return r;
    }
}
