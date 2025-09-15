#include "Member.h"

Member::Member(int id, std::string name) {
    this->id = id;
    this->name = name;
}

int Member::getId() const { return id; }
std::string Member::getName() const { return name; }

void Member::display() const {
    std::cout << "ID: " << id << "\t| Ten: " << name << std::endl;
}

std::string Member::toFileString() const {
    return std::to_string(id) + "," + name;
}
