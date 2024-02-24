#pragma once
#include "Object.h"

class ResidentialBuilding : public virtual Object {
protected:
    bool presenceOfGas;
    bool heater;

public:
    ResidentialBuilding();
    virtual ~ResidentialBuilding();

    void displayInfo();
    void setGasPresence(bool presence);
    void setHeater(bool hasHeater);
    bool getGasPresence();
};