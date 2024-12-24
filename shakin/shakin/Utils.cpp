#include "Utils.h"
#include <fstream>
#include <iomanip>
#include <ctime>

// Функция для логирования действий пользователя
void logAction(const std::string& actionDescription) {
    std::ofstream logFile("user_actions.log", std::ios::app); // Открыть файл в режиме добавления
    if (logFile.is_open()) {
        std::time_t now = std::time(nullptr);
        logFile << std::put_time(std::localtime(&now), "[%Y-%m-%d %H:%M:%S] ") << actionDescription << std::endl;
        logFile.close();
    }
    else {
        std::cerr << "Ошибка: не удалось открыть файл журнала." << std::endl;
    }
}

// Функция для загрузки данных из файла
bool loadFromFile(const std::string& filename, std::string& fileContent) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        fileContent.assign((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close();
        logAction("Загрузка данных из файла \"" + filename + "\" выполнена успешно.");
        return true;
    }
    else {
        logAction("Ошибка: не удалось загрузить данные из файла \"" + filename + "\".");
        return false;
    }
}

// Функция для сохранения данных в файл
bool saveToFile(const std::string& filename, const std::string& fileContent) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << fileContent;
        outFile.close();
        logAction("Сохранение данных в файл \"" + filename + "\" выполнено успешно.");
        return true;
    }
    else {
        logAction("Ошибка: не удалось сохранить данные в файл \"" + filename + "\".");
        return false;
    }
}

// Реализация шаблонов
template <typename T>
T getValidatedInput(const std::string& prompt, const T& minValue, const T& maxValue) {
    T value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= minValue && value <= maxValue) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка ввода
            return value;
        }
        else {
            std::cerr << "Ошибка: введите значение в диапазоне [" << minValue << ", " << maxValue << "]." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

template <>
std::string getValidatedInput<std::string>(const std::string& prompt, const std::string& minValue, const std::string& maxValue) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (!value.empty() && value >= minValue && value <= maxValue) {
            return value;
        }
        else {
            std::cerr << "Ошибка: введите корректное значение." << std::endl;
        }
    }
}

template <typename Container>
void printContainer(const Container& container, const std::string& delimiter) {
    for (const auto& element : container) {
        std::cout << element << delimiter;
    }
    std::cout << std::endl;
}

template <typename Container, typename Predicate>
Container filter(const Container& container, Predicate predicate) {
    Container result;
    for (const auto& element : container) {
        if (predicate(element)) {
            result.push_back(element);
        }
    }
    return result;
}

template <typename Container, typename EditFunction>
void batchEdit(Container& container, const std::vector<size_t>& indices, EditFunction editFunction) {
    for (size_t index : indices) {
        if (index < container.size()) {
            editFunction(container[index]);
        }
    }
}
