#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>

class Member {
private:
    int id;
    std::string name;

public:
    Member(int id, std::string name);

    int getId() const;
    std::string getName() const;

    void display() const;
    std::string toFileString() const;
};

#endif 
