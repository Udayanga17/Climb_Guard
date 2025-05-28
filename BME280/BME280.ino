#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Create BME280 object
Adafruit_BME280 bme;

// Optional: Set sea-level pressure in hPa for altitude calculation
#define SEALEVELPRESSURE_HPA 1013.25

void setup() {
  Serial.begin(115200);
  delay(1000);  // Allow time for Serial to initialize

  // Initialize BME280 sensor
  if (!bme.begin(0x76)) {  // Try 0x77 if 0x76 doesn't work
    Serial.println("❌ Could not find a valid BME280 sensor. Check wiring or I2C address.");
    while (1); // Stop here
  }

  Serial.println("✅ BME280 Sensor Initialized\n");
}

void loop() {
  // Read values from the sensor
  float temperature = bme.readTemperature();          // in °C
  float humidity = bme.readHumidity();                // in %
  float pressure = bme.readPressure() / 100.0F;       // in hPa
  float altitude = bme.readAltitude(SEALEVELPRESSURE_HPA); // in meters

  // Display values
  Serial.println("📊 BME280 Sensor Readings:");
  Serial.print("🌡️  Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("💧 Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("🌬️  Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("⛰️  Approx. Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");

  Serial.println("---------------------------");
  delay(2000);  // Delay between readings
}
