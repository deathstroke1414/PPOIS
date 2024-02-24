#include "Worker.h"
#include "Human.h"
#include "Object.h"

Worker::Worker(const std::string& name, int humanAge, int exp, double sal)
    : Human(name, humanAge), experience(exp), salary(sal), object(0) {}

Worker::Worker() {}

Worker::~Worker() {}

void Worker::displayInfo() {
    std::cout << "This is a worker." << std::endl;
}

int Worker::getExperience() const {
    return experience;
}

double Worker::getSalary() const {
    return salary;
}

void Worker::setWorkPlace(int obj) {
    object = obj;
}