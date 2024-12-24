#include "Pipe.h"
using namespace std;

Pipe::Pipe(int id, const string& name, double length, double diameter, bool inRepair)
    : id(id), name(name), length(length), diameter(diameter), inRepair(inRepair) {
}

int Pipe::getId() const { return id; }
string Pipe::getName() const { return name; }
bool Pipe::isInRepair() const { return inRepair; }

void Pipe::edit() {
    cout << "�������������� �����: " << name << endl;
    cout << "��������� �� ����� � �������? (1 - ��, 0 - ���): ";
    cin >> inRepair;
}

void Pipe::display() const {
    cout << "ID: " << id << ", ��������: " << name << ", �����: " << length
        << ", �������: " << diameter << ", ������: " << (inRepair ? "��" : "���") << endl;
}

void Pipe::saveToFile(ostream& out) const {
    out << id << endl
        << name << endl
        << length << endl
        << diameter << endl
        << inRepair << endl;
}

void Pipe::loadFromFile(istream& in) {
    in >> id;
    in.ignore();
    getline(in, name);
    in >> length >> diameter >> inRepair;
}
