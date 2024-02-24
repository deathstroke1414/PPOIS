#include <iostream>
#include <string>
#include <list>
#include "Human.h"
#include "Worker.h"
#include "Builder.h"
#include "OfficeWorker.h"
#include "Object.h"
#include "ResidentialBuilding.h"
#include "Apartment.h"
#include "PrivateHouse.h"
#include "Cottage.h"

using namespace std;


int main() {
    Cottage cottage;
    cottage.displayInfo();
    list<string> tools;
    tools.push_back("Hammer");
    tools.push_back("Saw");
    tools.push_back("Drill");

    Builder builder("John", 35, 5, 2500.0, tools);

    OfficeWorker officeWorker("Alice", 28, 3, 3000.0, 101);

    cottage.addWorker(&builder);
    cottage.addWorker(&officeWorker);

    cout << "Workers in the cottage:" << endl;
    const list<Worker*>& workers = cottage.getWorkers();
    for (const auto& worker : workers) {
        cout << "Name: " << worker->getName() << ", Age: " << worker->getAge() << ", Salary: " << worker->getSalary() << endl;
    }

    return 0;
}
