# Tsunami Early Warning System via WhatsApp (Sistem Tertanam dan IoT Project)

## Overview

A low-cost system using an IMU sensor and water level sensor to detect tsunamis. Sends real-time alerts via WhatsApp to registered users.

## Features

- **IMU Sensor**: Detects seismic activity.
- **Water Level Sensor**: Monitors sea level changes.
- **WhatsApp Alerts**: Sends warnings via PyWhatKit.
- **Customizable Thresholds**: Adjust sensitivity for detection.

## Hardware

- IMU Sensor (MPU6050)
- Water Level Sensor
- Microcontroller (ESP32)
- Power Supply
- WiFi Connection

## Software

- Arduino IDE
- Python (for WhatsApp integration)
- Python Libraries

## Setup

1. **Hardware**: Connect IMU and water level sensors to the microcontroller. Add Wi-Fi and power.
2. **Software**: Upload code to the microcontroller. Configure Twilio API for WhatsApp alerts.
3. **Test**: Simulate events to ensure alerts are sent.

## Code

- `imusensor.ino`: IMU data reading.
- `waterlevel_sensor.ino`: Water level data reading.
- `dbconnection.py`: Sends WhatsApp alerts.

## Example Alert

```
🚨 TSUNAMI WARNING 🚨
Seismic activity and rising water levels detected!
Take immediate action.
```

## Future Enhancements

- GPS integration for precise location.
- Mobile app for user management.
- Machine learning for better accuracy.
- Multi-channel alerts (SMS, email).

---

**Disclaimer**: This is a prototype. Always follow official tsunami warnings.
