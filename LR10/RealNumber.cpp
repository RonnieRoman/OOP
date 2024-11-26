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
    int thisIntPart = static_cast<int>(this->value);
    int otherIntPart = static_cast<int>(other.value);

    // Спершу порівнюємо цілі частини
    if (thisIntPart != otherIntPart) {
        return thisIntPart > otherIntPart;
    }

    // Якщо цілі частини однакові, порівнюємо дробові частини
    double thisFractionalPart = this->value - thisIntPart;
    double otherFractionalPart = other.value - otherIntPart;
    return thisFractionalPart > otherFractionalPart;
}

// Оператор []
double RealNumber::operator[](int) const {
    return value - static_cast<int>(value);  // Виділяємо дробову частину
}

// Метод для виведення об'єкта
void RealNumber::print() const {
    std::cout << value << std::endl;
}

// Статичний метод для сортування масиву за спаданням
void RealNumber::sortArray(RealNumber arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (!(arr[i] > arr[j])) {  // Використовуємо змінений оператор порівняння
                RealNumber temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
