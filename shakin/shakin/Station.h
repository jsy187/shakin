#pragma once
#include <string>
#include <iostream>

class Station {
private:
    int id;
    std::string name;
    int totalWorkshops; // ����� ���������� �����
    int activeWorkshops; // ���������� ��������������� �����
    double efficiency;   // ������������� ������ (������� �������� �����)

    void calculateEfficiency(); // ����������� �������������

public:
    Station(int id, const std::string& name, int totalWorkshops, int activeWorkshops);

    int getId() const;
    std::string getName() const;
    double getEfficiency() const;

    void edit();
    void display() const;

    void saveToFile(std::ostream& out) const;
    void loadFromFile(std::istream& in);
};
