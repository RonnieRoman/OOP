#include "Poizd.h"
#include <iostream>
#include <limits>

Poizd::Poizd(std::string n, double c, int d, int p)
    : Pasazhyr(n, c, d), passengers(p) {}

Poizd::~Poizd() {}

void Poizd::input() {
    Pasazhyr::input();

    while (true) {
        std::cout << "Введіть кількість пасажирів у поїзді: ";
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

void Poizd::display() const {
    std::cout << "Поїзд: " << name << "\n"
              << "Вартість: " << cost << "\n"
              << "Тривалість: " << duration << " годин\n";
}
