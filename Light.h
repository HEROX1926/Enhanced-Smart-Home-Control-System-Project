#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

class Light : public Device {
public:
    Light(std::string name);
    void control() override;
    void showStatus() const override;
};

#endif // LIGHT_H