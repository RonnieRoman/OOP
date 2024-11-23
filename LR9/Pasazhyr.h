#ifndef PASAZHYR_H
#define PASAZHYR_H

#include <string>

class Pasazhyr {
protected:
    std::string name; // Назва пасажирського перевезення
    double cost;      // Вартість
    int duration;     // Тривалість (години)

public:
    Pasazhyr(std::string n = "", double c = 0.0, int d = 0);
    virtual ~Pasazhyr();

    virtual void display() const = 0; // Чисто віртуальний метод
    virtual void input(); // Метод для введення даних
    virtual std::string getType() const = 0; // Віртуальний метод для отримання типу перевезення

    std::string getName() const;
    double getCost() const;
    int getDuration() const;

    void setName(std::string n);
    void setCost(double c);
    void setDuration(int d);
};

#endif
