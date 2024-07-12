#ifndef SMARTHOMESYSTEM_H
#define SMARTHOMESYSTEM_H

#include <vector>
#include <memory>
#include "Device.h"
#include "Light.h"
#include "Thermostat.h"
#include "SecurityCamera.h"

class SmartHomeSystem {
private:
    std::vector<std::shared_ptr<Device>> devices;
    bool isLoggedIn;
    bool authenticateUser();

public:
    SmartHomeSystem();
    void run();
    void displayMenu();
    void addDevice();
    void removeDevice();
    void controlDevice();
    void showStatus();
};

#endif // SMARTHOMESYSTEM_H