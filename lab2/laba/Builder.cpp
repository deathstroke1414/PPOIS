#include "Builder.h"
#include "Worker.h"

Builder::Builder() {}

Builder::Builder(const std::string& name, int humanAge, int exp, double sal, std::list<std::string> tools)
    : Worker(name, humanAge, exp, sal), tools(tools) {}

Builder::~Builder() {}

void Builder::displayInfo() {
    std::cout << "This is a builder." << std::endl;
}

void Builder::setTools(std::list<std::string> newTools) {
    tools = (newTools.size() != 0) ? newTools : std::list<std::string>();
}

std::list<std::string> Builder::getTools() const {
    return tools;
}