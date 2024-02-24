#pragma once
#include "Worker.h"

class OfficeWorker : public Worker {
protected:
    int officeNumber;

public:
    OfficeWorker(const std::string& name, int humanAge, int exp, double sal, int office);
    virtual ~OfficeWorker();

    void displayInfo();
    void setOfficeNumber(int number);
    int getOfficeNumber() const;
};
