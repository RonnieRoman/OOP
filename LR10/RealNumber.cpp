#include "RealNumber.h"
#include <iostream>
#include <cmath> 

// Конструктор
RealNumber::RealNumber(double v) : value(v) {}

// Деструктор
RealNumber::~RealNumber() {}

// Гетер
double RealNumber::getValue() const {
    return value;
}

// Оператор порівняння >
bool RealNumber::operator>(const RealNumber& other) const {
    return static_cast<int>(this->value) > static_cast<int>(other.value);
}

// Оператор []
double RealNumber::operator[](int) const {
    return value - static_cast<int>(value);  // Виділяємо дробову частину
}

// Метод для виведення об'єкта
void RealNumber::print() const {
    std::cout << value << std::endl;
}

// Статичний метод для сортування масиву
void RealNumber::sortArray(RealNumber arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j]) {
                RealNumber temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}