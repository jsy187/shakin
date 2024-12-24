#pragma once
#include <string>
#include <iostream>

class Station {
private:
    int id;
    std::string name;
    int totalWorkshops; // Общее количество цехов
    int activeWorkshops; // Количество задействованных цехов
    double efficiency;   // Эффективность работы (процент активных цехов)

    void calculateEfficiency(); // Пересчитать эффективность

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
