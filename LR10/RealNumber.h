#ifndef REALNUMBER_H
#define REALNUMBER_H

class RealNumber {
private:
    double value;

public:
    // Конструктор
    RealNumber(double v = 0.0);

    // Деструктор
    ~RealNumber();

    // Гетер для отримання значення
    double getValue() const;

    // Оператор порівняння >
    bool operator>(const RealNumber& other) const;

    // Оператор []
    double operator[](int) const;

    // Метод для виведення об'єкта
    void print() const;

    // Статичний метод для сортування масиву
    static void sortArray(RealNumber arr[], int size);
};

#endif
