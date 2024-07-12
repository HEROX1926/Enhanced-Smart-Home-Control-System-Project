#include "SecurityCamera.h"
#include <iostream>

SecurityCamera::SecurityCamera(std::string name) : Device(name), recording(false) {}

void SecurityCamera::control() {
    recording = !recording;
    std::cout << "Security Camera " << (recording ? "started recording.\n" : "stopped recording.\n");
}

void SecurityCamera::showStatus() const {
    std::cout << "Security Camera " << name << ": " << (recording ? "Recording" : "Not Recording") << ", " << (on ? "On" : "Off") << std::endl;
}