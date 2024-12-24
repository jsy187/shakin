#include "Station.h"
using namespace std;

Station::Station(int id, const string& name, int totalWorkshops, int activeWorkshops)
    : id(id), name(name), totalWorkshops(totalWorkshops), activeWorkshops(activeWorkshops) {
    calculateEfficiency();
}

void Station::calculateEfficiency() {
    if (totalWorkshops > 0) {
        efficiency = static_cast<double>(activeWorkshops) / totalWorkshops * 100;
    }
    else {
        efficiency = 0.0;
    }
}

int Station::getId() const {
    return id;
}

string Station::getName() const {
    return name;
}

double Station::getEfficiency() const {
    return efficiency;
}

void Station::edit() {
    cout << "�������������� ������������� �������: " << name << endl;
    cout << "������� ����� ���������� �������� ����� (�������� " << totalWorkshops << "): ";
    cin >> activeWorkshops;

    if (activeWorkshops < 0 || activeWorkshops > totalWorkshops) {
        cout << "������: ���������� �������� ����� ������ ���� �� 0 �� " << totalWorkshops << endl;
        return;
    }

    calculateEfficiency();
    cout << "������ ������� ���������." << endl;
}

void Station::display() const {
    cout << "ID: " << id
        << ", ��������: " << name
        << ", ����� �����: " << totalWorkshops
        << ", �������� �����: " << activeWorkshops
        << ", �������������: " << efficiency << "%" << endl;
}

void Station::saveToFile(ostream& out) const {
    out << id << endl
        << name << endl
        << totalWorkshops << endl
        << activeWorkshops << endl
        << efficiency << endl;
}

void Station::loadFromFile(istream& in) {
    in >> id;
    in.ignore();
    getline(in, name);
    in >> totalWorkshops >> activeWorkshops >> efficiency;
    calculateEfficiency(); // ���������, ��� ������������� �����������
}
