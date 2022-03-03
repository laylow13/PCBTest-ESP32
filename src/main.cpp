#include <Arduino.h>
#include "Wire.h"
#include <I2Cdev.h>
#include <MPU6050.h>
#include "imu.h"
#include "sd_drv.h"
#include "network.h"
MPU6050 imu;
SdCard sd;
int16_t ax, ay, az;
int16_t gx, gy, gz;
const char *ssid="eelab10010";
const char *password="18645089559";


void imu_test();
void imu_data_print();
void sd_test();
void http_test();

void setup() {
// write your initialization code here
Serial.begin(9600);
Serial.println("Hello world!");
wifi_connect(ssid,password);
http_test();
}
void loop() {
//imu_data_print();
delay(20);
}

void imu_test()
{
    Wire.begin(IMU_I2C_SDA, IMU_I2C_SCL);
//Wire.setClock(40000);
    imu.initialize();
    while (!imu.testConnection());
    Serial.println("connected!");
}
void imu_data_print()
{
    imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    Serial.print("[Gyro]:");
    Serial.print(gx);
    Serial.print(",");
    Serial.print(gy);
    Serial.print(",");
    Serial.println(gz);
}
void sd_test()
{
 sd.init();
}
void http_test()
{
    const char *serverPath="http://api.bilibili.com/x/relation/stat?vmid=438275172&jsonp=jsonp";
    String jsonBuffer;
    jsonBuffer = httpGETRequest(serverPath);
    JSONVar myObject = JSON.parse(jsonBuffer);
    // JSON.typeof(jsonVar) can be used to get the type of the var
    if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
    } else
    {
        Serial.print("bilibili follower:");
        Serial.println(myObject["data"]["follower"]);
    }
}