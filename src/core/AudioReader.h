#ifndef AUDIOREADER_H
#define AUDIOREADER_H

#include <iostream>

#include <sndfile.h>

#include <SignalData.h>

class AudioReader
{
public:
    AudioReader(const char *filename);
    SignalData *ReadSignalData(int maxsize = 0);

private:
    const char *filename_;
};

#endif