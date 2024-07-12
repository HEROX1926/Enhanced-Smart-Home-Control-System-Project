#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "Device.h"

class Thermostat : public Device {
private:
    int temperature;

public:
    Thermostat(std::string name);
    void control() override;
    void showStatus() const override;
};

#endif // THERMOSTAT_H