#ifndef INA219_PLUS_H
#define INA219_PLUS_H

#include <Arduino.h>
#include <Adafruit_INA219.h>

class INA219_Plus {
public:
    INA219_Plus();
    bool begin();

    float getCurrent_mA();
    float getPower_mW();
    float getEnergy_J();     // Energy in joules (Ws)
    void resetEnergy();
    void update();           // Call periodically to update energy

private:
    Adafruit_INA219 ina219;
    float totalEnergy_J;
    unsigned long lastUpdateTime_ms;
};

#endif
