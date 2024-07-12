#include "Thermostat.h"
#include <iostream>

Thermostat::Thermostat(std::string name) : Device(name), temperature(22) {}

void Thermostat::control() {
    std::cout << "Enter new temperature: ";
    std::cin >> temperature;
    std::cout << "Thermostat set to " << temperature << " degrees.\n";
}

void Thermostat::showStatus() const {
    std::cout << "Thermostat " << name << ": " << temperature << " degrees, " << (on ? "On" : "Off") << std::endl;
}