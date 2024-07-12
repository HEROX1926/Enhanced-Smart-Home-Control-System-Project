#include "Device.h"

Device::Device(std::string name) : name(name), on(false) {}

std::string Device::getName() const {
    return name;
}

bool Device::isOn() const {
    return on;
}