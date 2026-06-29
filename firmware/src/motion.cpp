#include <Wire.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#include "motion.h"
#include "config.h"

Adafruit_MPU6050 mpu;

sensors_event_t acceleration;
sensors_event_t gyro;
sensors_event_t temperature;

void initializeMPU()
{
    if(!mpu.begin())
    {
        while(true)
        {
            delay(100);
        }
    }

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

    mpu.setGyroRange(MPU6050_RANGE_500_DEG);

    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

bool detectShake()
{
    mpu.getEvent(&acceleration,&gyro,&temperature);

    return (
        abs(acceleration.acceleration.x) > SHAKE_THRESHOLD ||
        abs(acceleration.acceleration.y) > SHAKE_THRESHOLD ||
        abs(acceleration.acceleration.z) > SHAKE_THRESHOLD
    );
}

bool detectTiltLeft()
{
    mpu.getEvent(&acceleration,&gyro,&temperature);

    return acceleration.acceleration.x < -4;
}

bool detectTiltRight()
{
    mpu.getEvent(&acceleration,&gyro,&temperature);

    return acceleration.acceleration.x > 4;
}

bool detectFlip()
{
    mpu.getEvent(&acceleration,&gyro,&temperature);

    return acceleration.acceleration.z < -8;
}

float getAcceleration()
{
    mpu.getEvent(&acceleration,&gyro,&temperature);

    return acceleration.acceleration.x;
}