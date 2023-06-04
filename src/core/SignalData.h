#ifndef SIGNALDATA_H
#define SIGNALDATA_H

#include <vector>

class SignalData
{
public:
    SignalData(double sample_rate, std::vector<double> waveform);
    std::vector<double> waveform;
    double sample_rate;
    int size;
};

#endif