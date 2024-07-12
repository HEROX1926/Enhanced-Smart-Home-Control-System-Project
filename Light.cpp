#include "Light.h"
#include <iostream>

Light::Light(std::string name) : Device(name) {}

void Light::control() {
    on = !on;
    std::cout << "Light " << (on ? "turned on.\n" : "turned off.\n");
}

void Light::showStatus() const {
    std::cout << "Light " << name << ": " << (on ? "On" : "Off") << std::endl;
}