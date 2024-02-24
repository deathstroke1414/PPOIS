#include "Human.h"

Human::Human(const std::string& name, int humanAge) : FIO(name), age(humanAge) {}

Human::Human() {}

Human::~Human() {}

void Human::displayInfo() {
    std::cout << "This is a human." << std::endl;
}

std::string Human::getName() const {
    return FIO;
}

int Human::getAge() const {
    return age;
}

void Human::setFIO(std::string name) {
    FIO = name;
}

void Human::setAge(int age) {
    this->age = age;
}