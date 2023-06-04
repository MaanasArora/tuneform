#include <AudioReader.h>

#define BUFFER_LEN 1024

AudioReader::AudioReader(const char *filename)
{
    filename_ = filename;
}

SignalData *AudioReader::ReadSignalData(int maxsize)
{
    SF_INFO sfinfo;
    SNDFILE *infile;

    if (!(infile = sf_open(filename_, SFM_READ, &sfinfo)))
    {
        std::cout << "Could not read audio file." << std::endl;
        return NULL;
    }

    int readcount;
    double data[BUFFER_LEN];
    std::vector<double> signal;

    while ((readcount = (int)sf_read_double(infile, data, BUFFER_LEN)))
    {
        if (maxsize > 0)
            if (signal.size() >= maxsize)
                break;

        for (int i = 0; i < BUFFER_LEN; i++)
            signal.push_back(data[i]);
    }

    return new SignalData(48000, signal);
}