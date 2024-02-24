#include "ResidentialBuilding.h"
#include <iostream>

ResidentialBuilding::ResidentialBuilding() : presenceOfGas(false), heater(false) {}

ResidentialBuilding::~ResidentialBuilding() {}

void ResidentialBuilding::displayInfo() {
    std::cout << "This is a residential building." << std::endl;
}

void ResidentialBuilding::setGasPresence(bool presence) {
    presenceOfGas = presence;
}

void ResidentialBuilding::setHeater(bool hasHeater) {
    heater = hasHeater;
}

bool ResidentialBuilding::getGasPresence() {
    return presenceOfGas;
}