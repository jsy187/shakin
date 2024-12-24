#include <iostream>
#include <vector>
#include <string>
#include "Pipe.h"
#include "Station.h"
#include "Utils.h"

using namespace std;

// Меню программы
void printMenu() {
    cout << "\nМеню программы:\n";
    cout << "1. Добавить новую трубу\n";
    cout << "2. Добавить новую КС\n";
    cout << "3. Просмотреть все объекты\n";
    cout << "4. Редактировать трубу\n";
    cout << "5. Редактировать КС\n";
    cout << "6. Поиск объектов\n";
    cout << "7. Пакетное редактирование труб\n";
    cout << "8. Сохранить данные в файл\n";
    cout << "9. Загрузить данные из файла\n";
    cout << "0. Выход\n";
}

// Функция отображения всех объектов
void displayAllObjects(const vector<Pipe>& pipes, const vector<Station>& stations) {
    cout << "\nТрубы:\n";
    for (const auto& pipe : pipes) {
        cout << pipe << endl;
    }
    cout << "\nКомпрессорные станции:\n";
    for (const auto& station : stations) {
        cout << station << endl;
    }
}

// Основная программа
int main() {
    vector<Pipe> pipes;
    vector<Station> stations;

    bool running = true;
    while (running) {
        printMenu();
        int choice = getValidatedInput<int>("Выберите действие: ", 0, 9);

        switch (choice) {
        case 1: { // Добавить новую трубу
            Pipe newPipe;
            cin >> newPipe;
            pipes.push_back(newPipe);
            logAction("Добавлена новая труба: " + newPipe.getName());
            break;
        }
        case 2: { // Добавить новую КС
            Station newStation;
            cin >> newStation;
            stations.push_back(newStation);
            logAction("Добавлена новая КС: " + newStation.getName());
            break;
        }
        case 3: { // Просмотреть все объекты
            displayAllObjects(pipes, stations);
            logAction("Просмотр всех объектов");
            break;
        }
        case 4: { // Редактировать трубу
            size_t pipeId = getValidatedInput<size_t>("Введите ID трубы для редактирования: ", 0, pipes.size() - 1);
            pipes[pipeId].edit();
            logAction("Редактирование трубы с ID: " + to_string(pipeId));
            break;
        }
        case 5: { // Редактировать КС
            size_t stationId = getValidatedInput<size_t>("Введите ID КС для редактирования: ", 0, stations.size() - 1);
            stations[stationId].edit();
            logAction("Редактирование КС с ID: " + to_string(stationId));
            break;
        }
        case 6: { // Поиск объектов
            int filterChoice = getValidatedInput<int>(
                "Выберите фильтр (1 - трубы, 2 - КС): ", 1, 2);
            if (filterChoice == 1) { // Поиск труб
                bool inRepair = getValidatedInput<int>("Введите признак ремонта (0 - нет, 1 - да): ", 0, 1);
                auto filteredPipes = filter(pipes, [inRepair](const Pipe& pipe) {
                    return pipe.isInRepair() == inRepair;
                    });
                printContainer(filteredPipes);
                logAction("Поиск труб по признаку ремонта: " + to_string(inRepair));
            }
            else if (filterChoice == 2) { // Поиск КС
                int unusedPercent = getValidatedInput<int>("Введите процент незадействованных цехов: ", 0, 100);
                auto filteredStations = filter(stations, [unusedPercent](const Station& station) {
                    return station.getUnusedWorkshopsPercent() == unusedPercent;
                    });
                printContainer(filteredStations);
                logAction("Поиск КС по проценту незадействованных цехов: " + to_string(unusedPercent));
            }
            break;
        }
        case 7: { // Пакетное редактирование труб
            vector<size_t> pipeIndices;
            size_t count = getValidatedInput<size_t>("Введите количество труб для редактирования: ", 1, pipes.size());
            for (size_t i = 0; i < count; ++i) {
                size_t pipeId = getValidatedInput<size_t>(
                    "Введите ID трубы для редактирования: ", 0, pipes.size() - 1);
                pipeIndices.push_back(pipeId);
            }
            batchEdit(pipes, pipeIndices, [](Pipe& pipe) {
                pipe.edit();
                });
            logAction("Пакетное редактирование труб выполнено");
            break;
        }
        case 8: { // Сохранить данные в файл
            string filename = getValidatedInput<string>("Введите имя файла для сохранения: ", "", "");
            string data;
            for (const auto& pipe : pipes) {
                data += pipe.toString() + "\n";
            }
            for (const auto& station : stations) {
                data += station.toString() + "\n";
            }
            if (saveToFile(filename, data)) {
                cout << "Данные успешно сохранены.\n";
            }
            break;
        }
        case 9: { // Загрузить данные из файла
            string filename = getValidatedInput<string>("Введите имя файла для загрузки: ", "", "");
            string data;
            if (loadFromFile(filename, data)) {
                cout << "Данные успешно загружены.\n";
            }
            break;
        }
        case 0: { // Выход
            running = false;
            logAction("Завершение программы");
            break;
        }
        default:
            cerr << "Ошибка: выбрано некорректное действие.\n";
        }
    }

    return 0;
}