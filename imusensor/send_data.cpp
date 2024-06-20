#include "send_data.h"
#include "WiFi.h"
#include "HTTPClient.h"

void send_data(String sensor, String trig) {
  const char *host = "192.168.220.243";

  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("Connection Failed");
    return;
  }

  HTTPClient http;
  String Link = "http://192.168.220.243/tsunami-warning/?trig" + sensor + "=" + trig;
  Serial.println(Link);
  http.begin(client, Link);

  // Send HTTP GET request
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}