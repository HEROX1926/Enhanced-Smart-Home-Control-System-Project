#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
protected:
    std::string name;
    bool on;

public:
    Device(std::string name);
    virtual ~Device() = default;
    std::string getName() const;
    bool isOn() const;
    virtual void control() = 0;
    virtual void showStatus() const = 0;
};

#endif // DEVICE_H