#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "Device.h"

class SecurityCamera : public Device {
private:
    bool recording;

public:
    SecurityCamera(std::string name);
    void control() override;
    void showStatus() const override;
};

#endif // SECURITYCAMERA_H
