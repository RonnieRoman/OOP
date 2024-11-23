#include "Avtobus.h"
#include <iostream>
#include <limits>

Avtobus::Avtobus(std::string n, double c, int d, int p)
    : Pasazhyr(n, c, d), passengers(p) {}

Avtobus::~Avtobus() {}

void Avtobus::input() {
    Pasazhyr::input();

    while (true) {
        std::cout << "Введіть кількість пасажирів в автобусі: ";
        std::cin >> passengers;
        if (std::cin.fail() || passengers <= 0) {
            std::cout << "Кількість пасажирів має бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

void Avtobus::display() const {
    std::cout << "Автобус: " << name << "\n"
              << "Вартість: " << cost << "\n"
              << "Тривалість: " << duration << " годин\n";
}
