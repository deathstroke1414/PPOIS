#pragma once
#include <iostream>
#include <string>

class Human {
protected:
    std::string FIO;
    int age;

public:
    Human(const std::string& name, int humanAge);
    Human();
    virtual ~Human();

    void displayInfo();
    std::string getName() const;
    int getAge() const;
    void setFIO(std::string name);
    void setAge(int age);
};