#include "conn.h"
#include "WiFi.h"

void connectWiFi()
{
    const char *ssid = "WIFI@LIFT_GKB"; // choose your wireless ssid
    const char *password = "emangada";  // put your wireless password here.

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }

    Serial.println("Connected to the WiFi network");
    // Print local IP address and start web server
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP()); // show ip address when connected on serial monitor.
}