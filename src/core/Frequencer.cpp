#include <iostream>
#include <Frequencer.h>

Frequencer::Frequencer(int size, int bins)
{
    size_ = size;
    bins_ = bins;
}

void Frequencer::Initialize()
{
    in = fftw_alloc_real(size_);
    out = fftw_alloc_complex(1 + (size_ / 2));
    plan = fftw_plan_dft_r2c_1d(size_, in, out, FFTW_ESTIMATE);
}

void Frequencer::Finish()
{
    fftw_destroy_plan(plan);
    fftw_free(out);
}

void Frequencer::GetCurrentFFT(double *outarr)
{
    fftw_execute(plan);

    for (int i = 0; i < size_; i++)
        outarr[i] = sqrt(pow(out[i][0], 2) + pow(out[i][1], 2));
}

void Frequencer::GetWindowFFT(std::vector<double> window, double *outarr)
{
    std::copy(window.begin(), window.end(), in);

    GetCurrentFFT(outarr);
}

void Frequencer::GetSequenceFFT(std::vector<double> sequence, double *outarr)
{
    for (int i = 0; i < sequence.size() / size_; i++)
    {
        std::copy(sequence.begin() + i * size_,
                  sequence.begin() + (i + 1) * size_,
                  in);

        GetCurrentFFT(outarr + i * size_);
    }
}