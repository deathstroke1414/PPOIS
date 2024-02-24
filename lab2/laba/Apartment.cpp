#include "Apartment.h"
#include <iostream>

Apartment::Apartment() : floorAmount(0), bicycleParking(false), garbageChute(false) {}

Apartment::~Apartment() {}

void Apartment::displayInfo() {
    std::cout << "This is an apartment." << std::endl;
}

void Apartment::setFloorAmount(int floors) {
    floorAmount = floors;
}

void Apartment::setBicycleParking(bool hasParking) {
    bicycleParking = hasParking;
}

void Apartment::setGarbageChute(bool hasChute) {
    garbageChute = hasChute;
}

int Apartment::getFloorAmount() {
    return floorAmount;
}