#pragma once
#include "ResidentialBuilding.h"

class PrivateHouse : public virtual ResidentialBuilding {
protected:
    int roomsAmount;
    int bathroomsAmount;

public:
    PrivateHouse();
    virtual ~PrivateHouse();

    void displayInfo();
    void setRoomsAmount(int rooms);
    void setBathroomsAmount(int bathrooms);
};
