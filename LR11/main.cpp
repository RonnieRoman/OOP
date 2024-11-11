#include <iostream>
#include <vector>
#include "Train.h"
#include "Bus.h"

void printPassengerInfo(Passenger* p) {
    p->display();
}

int main() {
    std::vector<Passenger*> passengers;
    int choice;
    int numPassengers;

    std::cout << "Введіть кількість пасажирів: ";
    while (!(std::cin >> numPassengers) || numPassengers <= 0) {
        std::cout << "Невірний ввід. Будь ласка, введіть позитивне число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Введення інформації про кожного пасажира
    for (int i = 0; i < numPassengers; ++i) {
        std::cout << "\nВведіть інформацію для пасажира " << i + 1 << ":\n";
        std::cout << "Оберіть тип транспорту (1 - Потяг, 2 - Автобус): ";
        while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
            std::cout << "Невірний ввід. Введіть 1 для Потяга або 2 для Автобуса: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            Train* trainPassenger = new Train();
            trainPassenger->input();
            passengers.push_back(trainPassenger);
        } else {
            Bus* busPassenger = new Bus();
            busPassenger->input();
            passengers.push_back(busPassenger);
        }
    }

    std::cout << "\nІнформація про пасажирів:\n";
    for (auto& p : passengers) {
        printPassengerInfo(p);
    }

    // Очищення динамічної пам'яті
    for (auto& p : passengers) {
        delete p;
    }

    return 0;
}
