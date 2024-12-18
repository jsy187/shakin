#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#define NOMINMAX
#include <windows.h>

using namespace std;

// Структура для описания трубы
struct Pipe {
    string name;
    double length = 0;
    double diameter = 0;
    bool inRepair = false;
    bool exists = false; // Флаг существования
};

// Структура для описания КС
struct Station {
    string name;
    int totalShops = 0;
    int workingShops = 0;
    bool exists = false; // Флаг существования
};

// Функция ввода данных о трубе
void inputPipe(Pipe& pipe) {
    cout << "Введите название трубы: ";
    getline(cin >> ws, pipe.name);

    cout << "Введите длину трубы: ";
    while (!(cin >> pipe.length) || pipe.length <= 0) {
        cout << "Ошибка ввода! Введите положительное число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите диаметр трубы: ";
    while (!(cin >> pipe.diameter) || pipe.diameter <= 0) {
        cout << "Ошибка ввода! Введите положительное число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Находится ли труба в ремонте? (1 - да, 0 - нет): ";
    while (!(cin >> pipe.inRepair)) {
        cout << "Ошибка ввода! Введите 1 или 0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    pipe.exists = true; // Устанавливаем флаг существования
}

// Функция ввода данных о КС
void inputStation(Station& station) {
    cout << "Введите название КС: ";
    getline(cin >> ws, station.name);

    cout << "Введите общее количество цехов: ";
    while (!(cin >> station.totalShops) || station.totalShops <= 0) {
        cout << "Ошибка ввода! Введите положительное число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите количество работающих цехов: ";
    while (!(cin >> station.workingShops) || station.workingShops < 0 || station.workingShops > station.totalShops) {
        cout << "Ошибка ввода! Введите корректное число (0 - " << station.totalShops << "): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    station.exists = true; // Устанавливаем флаг существования
}

// Функция вывода данных о трубе
void outputPipe(const Pipe& pipe) {
    if (!pipe.exists) {
        cout << "Труба не добавлена.\n";
        return;
    }
    cout << "\nДанные о трубе:\n";
    cout << "Название трубы: " << pipe.name << endl;
    cout << "Длина трубы: " << pipe.length << " км" << endl;
    cout << "Диаметр трубы: " << pipe.diameter << " м" << endl;
    cout << "Статус ремонта: " << (pipe.inRepair ? "В ремонте" : "Не в ремонте") << endl;
}

// Функция вывода данных о КС
void outputStation(const Station& station) {
    if (!station.exists) {
        cout << "КС не добавлена.\n";
        return;
    }
    cout << "\nДанные о КС:\n";
    cout << "Название КС: " << station.name << endl;
    cout << "Общее количество цехов: " << station.totalShops << endl;
    cout << "Количество работающих цехов: " << station.workingShops << endl;
}

// Функция сохранения данных в файл
void saveToFile(const Pipe& pipe, const Station& station) {
    ofstream file("data.txt");
    if (file.is_open()) {
        file << pipe.exists << endl; // Сохраняем флаг
        if (pipe.exists) {
            file << pipe.name << endl;
            file << pipe.length << endl;
            file << pipe.diameter << endl;
            file << pipe.inRepair << endl;
        }

        file << station.exists << endl; // Сохраняем флаг
        if (station.exists) {
            file << station.name << endl;
            file << station.totalShops << endl;
            file << station.workingShops << endl;
        }

        file.close();
        cout << "Данные успешно сохранены в файл.\n";
    }
    else {
        cout << "Ошибка при открытии файла для записи!\n";
    }
}

// Функция загрузки данных из файла
void loadFromFile(Pipe& pipe, Station& station) {
    ifstream file("data.txt");
    if (file.is_open()) {
        file >> pipe.exists;
        if (pipe.exists) {
            file.ignore();
            getline(file, pipe.name);
            file >> pipe.length >> pipe.diameter >> pipe.inRepair;
        }

        file >> station.exists;
        if (station.exists) {
            file.ignore();
            getline(file, station.name);
            file >> station.totalShops >> station.workingShops;
        }

        file.close();
        cout << "Данные успешно загружены из файла.\n";
    }
    else {
        cout << "Ошибка при открытии файла для чтения!\n";
    }
}

// Функция редактирования данных о трубе
void editPipe(Pipe& pipe) {
    if (!pipe.exists) {
        cout << "Труба не добавлена. Нечего редактировать.\n";
        return;
    }

    cout << "Редактирование данных о трубе:\n";
    cout << "1. Название трубы: " << pipe.name << endl;
    cout << "2. Длина трубы: " << pipe.length << " км\n";
    cout << "3. Диаметр трубы: " << pipe.diameter << " м\n";
    cout << "4. Статус ремонта: " << (pipe.inRepair ? "В ремонте" : "Не в ремонте") << endl;

    int choice;
    cout << "Выберите поле для редактирования (1-4): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
    case 1:
        cout << "Введите новое название трубы: ";
        getline(cin, pipe.name);
        break;
    case 2:
        cout << "Введите новую длину трубы: ";
        while (!(cin >> pipe.length) || pipe.length <= 0) {
            cout << "Ошибка ввода! Введите положительное число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        break;
    case 3:
        cout << "Введите новый диаметр трубы: ";
        while (!(cin >> pipe.diameter) || pipe.diameter <= 0) {
            cout << "Ошибка ввода! Введите положительное число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        break;
    case 4:
        cout << "Труба в ремонте? (1 - да, 0 - нет): ";
        while (!(cin >> pipe.inRepair)) {
            cout << "Ошибка ввода! Введите 1 или 0: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        break;
    default:
        cout << "Неверный выбор!\n";
    }
}

// Функция редактирования данных о КС
void editStation(Station& station) {
    if (!station.exists) {
        cout << "КС не добавлена. Нечего редактировать.\n";
        return;
    }

    cout << "Редактирование данных о КС:\n";
    cout << "1. Название КС: " << station.name << endl;
    cout << "2. Общее количество цехов: " << station.totalShops << endl;
    cout << "3. Количество работающих цехов: " << station.workingShops << endl;

    int choice;
    cout << "Выберите поле для редактирования (1-3): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
    case 1:
        cout << "Введите новое название КС: ";
        getline(cin, station.name);
        break;
    case 2:
        cout << "Введите новое общее количество цехов: ";
        while (!(cin >> station.totalShops) || station.totalShops <= 0) {
            cout << "Ошибка ввода! Введите положительное число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        break;
    case 3:
        cout << "Введите новое количество работающих цехов: ";
        while (!(cin >> station.workingShops) || station.workingShops < 0 || station.workingShops > station.totalShops) {
            cout << "Ошибка ввода! Введите корректное число (0 - " << station.totalShops << "): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        break;
    default:
        cout << "Неверный выбор!\n";
    }
}

// главное меню
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Pipe pipe;
    Station station;

    int choice;
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить трубу\n";
        cout << "2. Добавить КС\n";
        cout << "3. Просмотр всех объектов\n";
        cout << "4. Редактировать трубу\n";
        cout << "5. Редактировать КС\n";
        cout << "6. Сохранить\n";
        cout << "7. Загрузить\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";

        if (!(cin >> choice)) { // Проверка на некорректный ввод
            cout << "Ошибка. Выберите правильное действие!\n";
            cin.clear(); // Очистка флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
            continue; // Переход к следующей итерации цикла
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка лишних символов после ввода

        switch (choice) {
        case 1: inputPipe(pipe); break;
        case 2: inputStation(station); break;
        case 3: outputPipe(pipe); outputStation(station); break;
        case 4: editPipe(pipe); break;
        case 5: editStation(station); break;
        case 6: saveToFile(pipe, station); break;
        case 7: loadFromFile(pipe, station); break;
        case 0: cout << "Выход из программы...\n"; return 0;
        default: cout << "Ошибка. Выберите правильное действие!\n";
        }
    }
}
