#ifndef MOTION_H
#define MOTION_H

void initializeMPU();

bool detectShake();

bool detectTiltLeft();

bool detectTiltRight();

bool detectFlip();

float getAcceleration();

#endif