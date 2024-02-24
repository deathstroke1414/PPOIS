#include "PrivateHouse.h"
#include <iostream>

PrivateHouse::PrivateHouse() : roomsAmount(0), bathroomsAmount(0) {}

PrivateHouse::~PrivateHouse() {}

void PrivateHouse::displayInfo() {
    std::cout << "This is a private house." << std::endl;
}

void PrivateHouse::setRoomsAmount(int rooms) {
    roomsAmount = rooms;
}

void PrivateHouse::setBathroomsAmount(int bathrooms) {
    bathroomsAmount = bathrooms;
}