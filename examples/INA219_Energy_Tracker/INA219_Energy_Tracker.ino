#include <INA219_Plus.h>

INA219_Plus sensor;

void setup() {
  Serial.begin(9600);
  while (!Serial);  // Wait for serial monitor

  if (!sensor.begin()) {
    Serial.println("Failed to initialize INA219 sensor. Check wiring.");
    while (1);  // Halt if sensor doesn't initialize
  }

  Serial.println("INA219_Plus Energy Tracker Started");
  sensor.resetEnergy();
}

void loop() {
  // Update energy calculation every second
  sensor.update();

  float current_mA = sensor.getCurrent_mA();
  float power_mW = sensor.getPower_mW();
  float energy_J = sensor.getEnergy_J();

  Serial.print("Current (mA): ");
  Serial.print(current_mA);
  Serial.print("\tPower (mW): ");
  Serial.print(power_mW);
  Serial.print("\tEnergy (J): ");
  Serial.println(energy_J);

  delay(1000);  // 1-second delay
}
