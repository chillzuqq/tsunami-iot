#include <Wire.h>
#include <MPU6050_tockn.h>
#include "conn.h"
#include "send_data.h"

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  connectWiFi();
}

void loop() {
  mpu6050.update();
  
  float accX = mpu6050.getAccX();
  float accY = mpu6050.getAccY();
  float accZ = mpu6050.getAccZ();
  
  float gyroX = mpu6050.getGyroX();
  float gyroY = mpu6050.getGyroY();
  float gyroZ = mpu6050.getGyroZ();
  
  float totalAcc = sqrt(accX * accX + accY * accY + accZ * accZ);
  float totalGyro = sqrt(gyroX * gyroX + gyroY * gyroY + gyroZ * gyroZ);
  

  Serial.print("Acc X: ");
  Serial.print(accX);
  Serial.print(" | Acc Y: ");
  Serial.print(accY);
  Serial.print(" | Acc Z: ");
  Serial.print(accZ);
  Serial.print(" | Gyro X: ");
  Serial.print(gyroX);
  Serial.print(" | Gyro Y: ");
  Serial.print(gyroY);
  Serial.print(" | Gyro Z: ");
  Serial.print(gyroZ);
  Serial.print(" | Total Acc: ");
  Serial.print(totalAcc);
  Serial.print(" | Total Gyro: ");
  Serial.println(totalGyro);
  
  if (totalAcc > 2.0 || totalGyro > 200) {
    Serial.println("Warning: Berbahaya!");
    send_data("2", "1");
  } else if (totalAcc > 1.5 || totalGyro > 150) {
    Serial.println("Ombak Tinggi");
    send_data("2","0");
  } else if (totalAcc > 1.0 || totalGyro > 100) {
    Serial.println("Ombak Sedang");
    send_data("2","0");
  } else if (totalAcc > 0.5 || totalGyro > 50) {
    Serial.println("Ombak Kecil");
    send_data("2","0");
  } else {
    Serial.println("Lagi damai nich");
    send_data("2","0");
  }
  
  delay(2000);
}