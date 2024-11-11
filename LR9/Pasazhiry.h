#ifndef PASAZHIRY_H
#define PASAZHIRY_H

#include <string>

class Avtobus;  // Оголошуємо клас, який буде дружнім до Pasazhiry

class Pasazhiry {
protected:
    std::string name;
    double cost;
    int duration; // Тривалість перевезення (години)

public:
    Pasazhiry(std::string n = "", double c = 0.0, int d = 0);
    virtual ~Pasazhiry();

    std::string getName() const;
    double getCost() const;
    int getDuration() const;

    virtual void display() const = 0;
    virtual void input(); // Метод для введення даних

    void setName(std::string n);
    void setCost(double c);
    void setDuration(int d);

    // Дружні класи та функції для доступу до приватних членів
    friend class Avtobus;  // Клас Avtobus буде мати доступ до приватних членів Pasazhiry
};

#endif
