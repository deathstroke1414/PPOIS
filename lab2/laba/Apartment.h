#pragma once
#include "ResidentialBuilding.h"

class Apartment : public virtual ResidentialBuilding {
protected:
    int floorAmount;
    bool bicycleParking;
    bool garbageChute;

public:
    Apartment();
    virtual ~Apartment();

    void displayInfo();
    void setFloorAmount(int floors);
    void setBicycleParking(bool hasParking);
    void setGarbageChute(bool hasChute);
    int getFloorAmount();
};