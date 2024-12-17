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

// Функция для вывода данных о трубе
void outputPipe(const Pipe& pipe) {
    cout << "Название трубы: " << pipe.name << endl;
    cout << "Длина трубы: " << pipe.length << " км" << endl;
    cout << "Диаметр трубы: " << pipe.diameter << " м" << endl;
    cout << "Статус ремонта: " << (pipe.inRepair ? "В ремонте" : "Не в ремонте") << endl;
}

// Функция для вывода данных о КС
void outputStation(const Station& station) {
    cout << "Название КС: " << station.name << endl;
    cout << "Общее количество цехов: " << station.totalShops << endl;
    cout << "Количество работающих цехов: " << station.workingShops << endl;
    cout << "Эффективность: " << station.efficiency << endl;
}
// Функция для изменения статуса трубы
void editPipeRepairStatus(Pipe& pipe) {
    pipe.inRepair = !pipe.inRepair;
    cout << "Статус ремонта изменен на " << (pipe.inRepair ? "В ремонте" : "Не в ремонте") << endl;
}

// Функция для изменения количества работающих цехов
void editStationShops(Station& station) {
    int choice;
    cout << "Введите 1 для запуска цеха или 0 для остановки: ";
    cin >> choice;

    if (choice == 1) {
        if (station.workingShops < station.totalShops) {
            station.workingShops++;
            cout << "Цех запущен. Рабочих цехов: " << station.workingShops << endl;
        }
        else {
            cout << "Все цеха уже работают." << endl;
        }
    }
    else if (choice == 0) {
        if (station.workingShops > 0) {
            station.workingShops--;
            cout << "Цех остановлен. Рабочих цехов: " << station.workingShops << endl;
        }
        else {
            cout << "Нет работающих цехов для остановки." << endl;
        }
    }
    else {
        cout << "Неверный ввод." << endl;
    }
}
