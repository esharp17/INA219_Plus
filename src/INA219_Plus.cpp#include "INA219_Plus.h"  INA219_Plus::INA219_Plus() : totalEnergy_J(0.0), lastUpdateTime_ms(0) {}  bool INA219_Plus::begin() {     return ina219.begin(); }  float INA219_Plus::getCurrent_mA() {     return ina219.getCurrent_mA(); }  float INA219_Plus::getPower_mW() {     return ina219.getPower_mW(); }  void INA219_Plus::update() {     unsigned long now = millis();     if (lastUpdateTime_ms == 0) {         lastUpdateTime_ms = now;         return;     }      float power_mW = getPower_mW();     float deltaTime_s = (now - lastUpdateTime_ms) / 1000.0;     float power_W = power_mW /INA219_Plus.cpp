#include "INA219_Plus.h"

INA219_Plus::INA219_Plus() : totalEnergy_J(0.0), lastUpdateTime_ms(0) {}

bool INA219_Plus::begin() {
    return ina219.begin();
}

float INA219_Plus::getCurrent_mA() {
    return ina219.getCurrent_mA();
}

float INA219_Plus::getPower_mW() {
    return ina219.getPower_mW();
}

void INA219_Plus::update() {
    unsigned long now = millis();
    if (lastUpdateTime_ms == 0) {
        lastUpdateTime_ms = now;
        return;
    }

    float power_mW = getPower_mW();
    float deltaTime_s = (now - lastUpdateTime_ms) / 1000.0;
    float power_W = power_mW / 1000.0;

    totalEnergy_J += power_W * deltaTime_s;

    lastUpdateTime_ms = now;
}

float INA219_Plus::getEnergy_J() {
    return totalEnergy_J;
}

void INA219_Plus::resetEnergy() {
    totalEnergy_J = 0.0;
    lastUpdateTime_ms = millis();
}
