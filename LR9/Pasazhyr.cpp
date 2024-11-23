#include "Pasazhyr.h"
#include <iostream>
#include <limits>

Pasazhyr::Pasazhyr(std::string n, double c, int d) : name(n), cost(c), duration(d) {}

Pasazhyr::~Pasazhyr() {}

std::string Pasazhyr::getName() const {
    return name;
}

double Pasazhyr::getCost() const {
    return cost;
}

int Pasazhyr::getDuration() const {
    return duration;
}

void Pasazhyr::setName(std::string n) {
    name = n;
}

void Pasazhyr::setCost(double c) {
    if (c >= 0)
        cost = c;
    else
        std::cout << "Вартість не може бути негативною!" << std::endl;
}

void Pasazhyr::setDuration(int d) {
    if (d >= 0)
        duration = d;
    else
        std::cout << "Тривалість не може бути негативною!" << std::endl;
}

void Pasazhyr::input() {
    // Очищення буфера на початку введення
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Перевірка введення назви перевезення
    while (true) {
        std::cout << "Введіть назву пасажирського перевезення: ";
        std::getline(std::cin, name);
        
        if (!name.empty()) {
            break;
        } else {
            std::cout << "Назва не може бути порожньою. Спробуйте ще раз.\n";
        }
    }

    // Перевірка введення вартості
    while (true) {
        std::cout << "Введіть вартість перевезення: ";
        std::cin >> cost;
        if (std::cin.fail() || cost < 0) {
            std::cout << "Вартість має бути числом більше або рівне 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            setCost(cost);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення потоку
            break;
        }
    }

    // Перевірка введення тривалості
    while (true) {
        std::cout << "Введіть тривалість перевезення (години): ";
        std::cin >> duration;
        if (std::cin.fail() || duration < 0) {
            std::cout << "Тривалість має бути числом більше або рівне 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            setDuration(duration);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення потоку
            break;
        }
    }
}
