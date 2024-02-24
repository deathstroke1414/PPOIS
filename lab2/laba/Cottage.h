#pragma once
#include "Apartment.h"
#include "PrivateHouse.h"

class Cottage : public Apartment, public PrivateHouse {
protected:
    int bedroomsAmount;

public:
    Cottage();
    virtual ~Cottage();

    void displayInfo();
    void setBedroomsAmount(int bedrooms);
    int getBedroomsAmount();
};