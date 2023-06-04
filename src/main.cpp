#include <iostream>

#include <AudioReader.h>
#include <SignalData.h>
#include <Frequencer.h>

int main(int argc, char *argv[])
{
    AudioReader *reader = new AudioReader(argv[1]);

    SignalData *data = reader->ReadSignalData(10000);

    double out[data->size];
    Frequencer *frequencer = new Frequencer(1000, 10);
    frequencer->Initialize();
    frequencer->GetSequenceFFT(data->waveform, out);
    frequencer->Finish();

    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << out[i] << " ";
    std::cout << std::endl;

    return 0;
}