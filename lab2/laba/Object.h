#pragma once

#include "Worker.h"
#include <list>

class Object {
protected:
    int id;
    int daysUnderConstruction;
    int totalDays;
    std::list<Worker*> workers;
    
public:
    Object();
    ~Object();

    int getId();
    void displayInfo();
    void addWorker(Worker* worker);
    std::list<Worker*>& getWorkers();
};


