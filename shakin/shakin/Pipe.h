#pragma once
#include <string>
#include <iostream>

class Pipe {
private:
    int id;
    std::string name;
    double length;
    double diameter;
    bool inRepair;

public:
    Pipe(int id, const std::string& name, double length, double diameter, bool inRepair);

    int getId() const;
    std::string getName() const;
    bool isInRepair() const;

    void edit();
    void display() const;

    void saveToFile(std::ostream& out) const;
    void loadFromFile(std::istream& in);
};

