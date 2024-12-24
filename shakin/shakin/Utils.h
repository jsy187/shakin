#pragma once
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

// Декларации функций, не зависящих от шаблонов
void logAction(const std::string& actionDescription);  // Логирование действий
bool loadFromFile(const std::string& filename, std::string& fileContent); // Загрузка данных из файла
bool saveToFile(const std::string& filename, const std::string& fileContent); // Сохранение данных в файл

// Универсальные шаблоны для различных действий
template <typename T>
T getValidatedInput(const std::string& prompt, const T& minValue, const T& maxValue);

template <>
std::string getValidatedInput<std::string>(const std::string& prompt, const std::string& minValue, const std::string& maxValue);

template <typename Container>
void printContainer(const Container& container, const std::string& delimiter = ", ");

template <typename Container, typename Predicate>
Container filter(const Container& container, Predicate predicate);

template <typename Container, typename EditFunction>
void batchEdit(Container& container, const std::vector<size_t>& indices, EditFunction editFunction);
