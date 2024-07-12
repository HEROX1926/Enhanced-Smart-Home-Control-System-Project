#include "SmartHomeSystem.h"
#include <iostream>

SmartHomeSystem::SmartHomeSystem() : isLoggedIn(false) {}

bool SmartHomeSystem::authenticateUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    // For simplicity, use hardcoded credentials
    return (username == "admin" && password == "password");
}

void SmartHomeSystem::run() {
    if (authenticateUser()) {
        isLoggedIn = true;
        while (isLoggedIn) {
            displayMenu();
            int choice;
            std::cin >> choice;
            switch (choice) {
                case 1: 
                    addDevice(); 
                    break;
                case 2: 
                    removeDevice(); 
                    break;
                case 3: 
                    controlDevice(); 
                    break;
                case 4: 
                    showStatus(); 
                    break;
                case 5: 
                    isLoggedIn = false; 
                    break;
                default: 
                    std::cout << "Invalid choice!" << std::endl;
            }
        }
    } 
    else {
        std::cout << "Authentication failed!" << std::endl;
    }
}

void SmartHomeSystem::displayMenu() {
    std::cout << "1. Add Device\n2. Remove Device\n3. Control Device\n4. Show Status\n5. Logout\nChoose an option: ";
}

void SmartHomeSystem::addDevice() {
    std::cout << "Select device type to add: \n1. Light\n2. Thermostat\n3. Security Camera\n";
    int choice;
    std::cin >> choice;
    std::string name;
    std::cout << "Enter device name: ";
    std::cin >> name;
    
    switch (choice) {
        case 1:
            devices.push_back(std::make_shared<Light>(name));
            std::cout << "Light added.\n";
            break;
        case 2:
            devices.push_back(std::make_shared<Thermostat>(name));
            std::cout << "Thermostat added.\n";
            break;
        case 3:
            devices.push_back(std::make_shared<SecurityCamera>(name));
            std::cout << "Security Camera added.\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
    }
}

void SmartHomeSystem::removeDevice() {
    std::string name;
    std::cout << "Enter device name to remove: ";
    std::cin >> name;
    for (auto it = devices.begin(); it != devices.end(); ++it) {
        if ((*it)->getName() == name) {
            devices.erase(it);
            std::cout << "Device removed.\n";
            return;
        }
    }
    std::cout << "Device not found.\n";
}

void SmartHomeSystem::controlDevice() {
    std::string name;
    std::cout << "Enter device name to control: ";
    std::cin >> name;
    for (auto& device : devices) {
        if (device->getName() == name) {
            device->control();
            return;
        }
    }
    std::cout << "Device not found.\n";
}

void SmartHomeSystem::showStatus() {
    if (devices.empty()) {
        std::cout << "No devices added.\n";
    } 
    else {
        for (const auto& device : devices) {
            device->showStatus();
        }
    }
}