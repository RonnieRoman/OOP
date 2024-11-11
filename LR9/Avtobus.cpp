#include "Avtobus.h"
#include <iostream>
#include <limits>

Avtobus::Avtobus(std::string n, double c, int d, int p)
    : Pasazhiry(n, c, d), passengers(p) {}

Avtobus::~Avtobus() {}

int Avtobus::getPassengers() const {
    return passengers;
}

void Avtobus::setPassengers(int p) {
    if (p >= 0) {
        passengers = p;
    } else {
        std::cout << "Кількість пасажирів не може бути негативною!" << std::endl;
    }
}

void Avtobus::display() const {
    std::cout << "Тип перевезення: Автобус\n";
    std::cout << "Назва: " << getName() << "\n";
    std::cout << "Вартість: " << getCost() << "\n";
    std::cout << "Тривалість: " << getDuration() << " годин\n";
    std::cout << "Кількість пасажирів: " << passengers << "\n";
}

void Avtobus::input() {
    Pasazhiry::input();

    while (true) {
        std::cout << "Введіть кількість пасажирів: ";
        std::cin >> passengers;
        if (std::cin.fail() || passengers < 0) {
            std::cout << "Кількість пасажирів має бути числом більше або рівне 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}
