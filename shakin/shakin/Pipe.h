#pragma once
#include <string>
#include <iostream>

using namespace std;

class Pipe {
private:
    int id;
    string name;
    bool inRepair;

public:
    Pipe() : id(0), name(""), inRepair(false) {}

    friend ostream& operator<<(ostream& out, const Pipe& pipe);
    friend istream& operator>>(istream& in, Pipe& pipe);

    string toString() const;

    // Getters and Setters
    int getId() const { return id; }
    void setId(int newId) { id = newId; }

    bool isInRepair() const { return inRepair; }
    void setInRepair(bool repair) { inRepair = repair; }
};
