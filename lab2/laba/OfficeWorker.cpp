#include "OfficeWorker.h"
#include "Worker.h"

OfficeWorker::OfficeWorker(const std::string& name, int humanAge, int exp, double sal, int office)
    : Worker(name, humanAge, exp, sal), officeNumber(office) {}

OfficeWorker::~OfficeWorker() {}

void OfficeWorker::displayInfo() {
    std::cout << "This is an office worker." << std::endl;
}

void OfficeWorker::setOfficeNumber(int number) {
    officeNumber = number;
}

int OfficeWorker::getOfficeNumber() const {
    return officeNumber;
}