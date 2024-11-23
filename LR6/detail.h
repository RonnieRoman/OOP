#ifndef DETAIL_H
#define DETAIL_H

#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

// Розмір масиву деталей
const int SIZE = 3;

// Структура для збереження інформації про деталі
struct detail_s_t {
    int id;
    string name;
    double price;
};

// Оголошення класу DetailManager
class DetailManager {
private:
    std::array<detail_s_t, SIZE> details;
    int nextId;

public:
    // Конструктор
    DetailManager();

    // Деструктор
    ~DetailManager();

    // Метод для введення нових деталей
    void inputDetails();

    // Метод для виведення даних
    void displayDetails() const;

    // Метод для фільтрації за назвою або ціною
    void filterDetails() const;

    // Метод для оновлення даних за ID
    void updateDetailById();

    // Метод для видалення деталі за ID
    void deleteDetailById();

    // Перевірка валідності ціни
    bool isValidPrice(double price);

    // Пошук індексу деталі за ID
    int findDetailIndexById(int id) const;
};

#endif