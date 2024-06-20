#include "conn.h"
#include "send_data.h"

// Define the analog pin connected to the water level sensor
#define WATER_LEVEL_PIN 14

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Water Level Sensor Initialized");
  connectWiFi();
}

void loop() {
  // Baca water level
  int waterLevel = analogRead(WATER_LEVEL_PIN);
  
  // ini kondisi ya

  // 3/4 kena air
  if (waterLevel >= 2100) {
    Serial.println("Water Level: Aman");
    send_data("1", "0");
  
  // 1/2 kena air
  } else if (waterLevel >= 1800 && waterLevel < 2099) {
    Serial.println("Water Level: Peringatan");
    send_data("1", "0");
  
  // 1/4 kena air
  // ini trig1
  } else if (waterLevel >= 1500 && waterLevel < 1799) {
    Serial.println("Water Level: WARNING");
    send_data("1", "1");

  // kering wak
  } else if (waterLevel >= 0 && waterLevel < 1499) {
    Serial.println("Water Level: TSUNAMI");
    send_data("1", "1");
  }

  // ngecek inputnya berapa
  // Serial.print("Water Level: ");
  // Serial.println(waterLevel);
  delay(1000);
  
  // 3/4 itu diatas 2100
  // 1/2 1800 keatas - dibawah 2100
  // 1/4 dibawah 1800 - diatas 1700
  // kalau gak kedetect air dibawah 950 
}
