#include <SignalData.h>

SignalData::SignalData(double sample_rate, std::vector<double> waveform)
{
    this->waveform = waveform;
    this->sample_rate = sample_rate;
    this->size = waveform.size();
}