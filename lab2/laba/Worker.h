#pragma once
#include "Human.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Worker : public virtual Human {
protected:
    int experience;
    double salary;
    int object;

public:
    Worker(const std::string& name, int humanAge, int exp, double sal);
    Worker();
    ~Worker();

    void displayInfo();
    int getExperience() const;
    double getSalary() const;
    void setWorkPlace(int obj);
};
