#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Структура для описания трубы
struct Pipe {
    string name;      // Название (с поддержкой пробелов)
    double length;    // Длина
    double diameter;  // Диаметр
    bool inRepair;    // Признак "в ремонте"
};

// Структура для описания КС
struct Station {
    string name;            // Название
    int totalShops;         // Общее количество цехов
    int workingShops;       // Количество работающих цехов
    double efficiency;      // Показатель эффективности
};

