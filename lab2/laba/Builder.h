#pragma once
#include "Worker.h"
#include <list>
#include <string>

class Builder : public Worker {
protected:
    std::list<std::string> tools;

public:
    Builder();
    Builder(const std::string& name, int humanAge, int exp, double sal, std::list<std::string> tools);
    virtual ~Builder();

    void displayInfo();
    void setTools(std::list<std::string> newTools);
    std::list<std::string> getTools() const;
};