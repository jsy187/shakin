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


// Функция для ввода данных о трубе
void inputPipe(Pipe& pipe) {
    cout << "Введите название трубы: ";
    getline(cin >> ws, pipe.name);  // Ввод с пробелами
    cout << "Введите длину трубы: ";
    cin >> pipe.length;
    cout << "Введите диаметр трубы: ";
    cin >> pipe.diameter;
    cout << "Находится ли труба в ремонте? (1 - да, 0 - нет): ";
    cin >> pipe.inRepair;
}

// Функция для ввода данных о КС
void inputStation(Station& station) {
    cout << "Введите название КС: ";
    getline(cin >> ws, station.name);
    cout << "Введите общее количество цехов: ";
    cin >> station.totalShops;
    cout << "Введите количество работающих цехов: ";
    cin >> station.workingShops;
    cout << "Введите показатель эффективности: ";
    cin >> station.efficiency;
}

