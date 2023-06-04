#ifndef FREQUENCER_H
#define FREQUENCER_H

#include <vector>
#include <fftw3.h>
#include <stdlib.h>
#include <math.h>

class Frequencer
{
public:
    Frequencer(int size, int bins);
    void Initialize();
    void Finish();
    void GetWindowFFT(std::vector<double> window, double *outarr);
    void GetSequenceFFT(std::vector<double> sequence, double *outarr);

private:
    int size_;
    int bins_;
    double *in;
    fftw_complex *out;
    fftw_plan plan;
    void GetCurrentFFT(double *outarr);
};

#endif