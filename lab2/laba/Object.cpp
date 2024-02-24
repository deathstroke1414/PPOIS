#include "Object.h"
#include <algorithm>

Object::Object(){}

Object::~Object() {}

void Object::displayInfo() {
    std::cout << "This is an object." << std::endl;
}

void Object::addWorker(Worker* worker) {
    workers.push_back(worker);
    worker->setWorkPlace(getId());
}

int Object::getId() {
    return id;
}

std::list<Worker*>& Object::getWorkers() {
    return workers;
}