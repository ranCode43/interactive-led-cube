#ifndef MICROPHONE_H
#define MICROPHONE_H

void initializeMic();

int getVolume();

bool detectBeat();

bool detectClap();

bool isQuiet();

#endif