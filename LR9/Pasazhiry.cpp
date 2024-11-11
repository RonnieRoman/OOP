#include "Pasazhiry.h"
#include <iostream>
#include <limits>

Pasazhiry::Pasazhiry(std::string n, double c, int d) : name(n), cost(c), duration(d) {}

Pasazhiry::~Pasazhiry() {}

std::string Pasazhiry::getName() const {
    return name;
}

double Pasazhiry::getCost() const {
    return cost;
}

int Pasazhiry::getDuration() const {
    return duration;
}

void Pasazhiry::setName(std::string n) {
    name = n;
}

void Pasazhiry::setCost(double c) {
    if (c >= 0)
        cost = c;
    else
        std::cout << "Вартість не може бути негативною!" << std::endl;
}

void Pasazhiry::setDuration(int d) {
    if (d >= 0)
        duration = d;
    else
        std::cout << "Тривалість не може бути негативною!" << std::endl;
}

void Pasazhiry::input() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    while (true) {
        std::cout << "Введіть назву перевезення: ";
        std::getline(std::cin, name);
        if (!name.empty()) {
            break;
        } else {
            std::cout << "Назва не може бути порожньою. Спробуйте ще раз.\n";
        }
    }

    while (true) {
        std::cout << "Введіть вартість перевезення: ";
        std::cin >> cost;
        if (std::cin.fail() || cost < 0) {
            std::cout << "Вартість має бути числом більше або рівне 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            setCost(cost);
            break;
        }
    }

    while (true) {
        std::cout << "Введіть тривалість перевезення (години): ";
        std::cin >> duration;
        if (std::cin.fail() || duration < 0) {
            std::cout << "Тривалість має бути числом більше або рівне 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            setDuration(duration);
            break;
        }
    }
}
