//
// Created by Lay on 2/28/2022.
//

#ifndef PCBTEST_IMU_H
#define PCBTEST_IMU_H

#include "MPU6050.h"

#define IMU_I2C_SDA 16  //need to be edited!
#define IMU_I2C_SCL 17


extern int32_t encoder_diff;

class IMU
{
private:
    MPU6050 imu;
    int flag;
    int16_t ax, ay, az;
    int16_t gx, gy, gz;

    long  last_update_time;

public:
    void init();

    void update(int interval);

    int16_t getAccelX();
    int16_t getAccelY();
    int16_t getAccelZ();

    int16_t getGyroX();
    int16_t getGyroY();
    int16_t getGyroZ();

};

#endif //PCBTEST_IMU_H
