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

