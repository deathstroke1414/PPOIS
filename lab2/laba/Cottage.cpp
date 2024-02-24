#include "Cottage.h"
#include <iostream>

Cottage::Cottage() : bedroomsAmount(0) {}

Cottage::~Cottage() {}

void Cottage::displayInfo() {
    std::cout << "This is a cottage." << std::endl;
}

void Cottage::setBedroomsAmount(int bedrooms) {
    bedroomsAmount = bedrooms;
}

int Cottage::getBedroomsAmount() {
   return bedroomsAmount;
}