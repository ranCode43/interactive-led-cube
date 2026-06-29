#ifndef CUBE_STATE_H
#define CUBE_STATE_H

struct CubeState
{
    bool beatDetected;

    bool clapDetected;

    bool shakeDetected;

    bool tiltLeft;

    bool tiltRight;

    bool flipDetected;

    bool buttonPressed;

    int microphoneVolume;

    int currentMode;
};

extern CubeState cubeState;

#endif