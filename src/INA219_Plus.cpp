#include <INA219_Plus.h>

INA219_Plus sensor;

void setup() {
  Serial.begin(9600);
  if (!sensor.begin()) {
    Serial.println("INA219 not found");
    while (1);
  }
}

void loop() {
  sensor.update();

  Serial.print("Current (mA): ");
  Serial.println(sensor.getCurrent_mA());

  Serial.print("Power (mW): ");
  Serial.println(sensor.getPower_mW());

  Serial.print("Energy (J): ");
  Serial.println(sensor.getEnergy_J());

  delay(1000);  // Update every second
}
