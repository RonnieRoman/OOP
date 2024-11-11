#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include <limits>

class Passenger {
protected:
    std::string name;
    int ticketNumber;
public:
    Passenger(std::string name = "", int ticketNumber = 0)
        : name(name), ticketNumber(ticketNumber) {}

    virtual void input() {
        std::cout << "Введіть ім'я пасажира: ";
        std::getline(std::cin, name);
        while (name.empty()) {
            std::cout << "Ім'я не може бути порожнім. Введіть ім'я пасажира ще раз: ";
            std::getline(std::cin, name);
        }

        std::cout << "Введіть номер квитка: ";
        while (!(std::cin >> ticketNumber)) {
            std::cout << "Невірний ввід. Введіть правильний номер квитка: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    virtual void display() const {
        std::cout << "Пасажир: " << name << ", Номер квитка: " << ticketNumber << std::endl;
    }

    virtual ~Passenger() {}
};

#endif
