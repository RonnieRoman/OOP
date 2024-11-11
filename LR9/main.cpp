#include <iostream>
#include <vector>
#include "Poizd.h"
#include "Avtobus.h"
#include "Pasazhiry.h"

int main() {
    std::vector<Pasazhiry*> pasazhiry;
    int totalPassengers = 0;
    double totalCost = 0.0;
    int totalDuration = 0;

    int poizdCount = 0;
    int avtobusCount = 0;

    // Запитуємо кількість перевезень поїздами з перевіркою
    while (true) {
        std::cout << "Скільки перевезень поїздом ви хочете додати? ";
        std::cin >> poizdCount;
        if (std::cin.fail() || poizdCount < 1) {
            std::cout << "Кількість перевезень повинна бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Запитуємо кількість перевезень автобусами з перевіркою
    while (true) {
        std::cout << "Скільки перевезень автобусом ви хочете додати? ";
        std::cin >> avtobusCount;
        if (std::cin.fail() || avtobusCount < 1) {
            std::cout << "Кількість перевезень повинна бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Введення даних для поїздів
    for (int i = 0; i < poizdCount; i++) {
        std::cout << "\nВведення даних для перевезення поїздом №" << (i + 1) << ":\n";
        Poizd* p = new Poizd();
        p->input();
        pasazhiry.push_back(p);
    }

    // Введення даних для автобусів
    for (int i = 0; i < avtobusCount; i++) {
        std::cout << "\nВведення даних для перевезення автобусом №" << (i + 1) << ":\n";
        Avtobus* a = new Avtobus();
        a->input();
        pasazhiry.push_back(a);
    }

    // Виведення даних та підрахунок результатів
    for (const auto& p : pasazhiry) {
        p->display();
        std::cout << "---------------------\n";

        if (dynamic_cast<Poizd*>(p)) {
            totalPassengers += dynamic_cast<Poizd*>(p)->getPassengers();
        } else if (dynamic_cast<Avtobus*>(p)) {
            totalPassengers += dynamic_cast<Avtobus*>(p)->getPassengers();
        }

        totalCost += p->getCost();
        totalDuration += p->getDuration();
    }

    std::cout << "Загальна кількість пасажирів: " << totalPassengers << "\n";

    int totalCount = poizdCount + avtobusCount;
    if (totalCount > 0) {
        double avgCost = totalCost / totalCount;
        double avgDuration = static_cast<double>(totalDuration) / totalCount;

        std::cout << "Середня вартість перевезення: " << avgCost << "\n";
        std::cout << "Середня тривалість перевезення: " << avgDuration << " годин\n";
    }

    for (auto& p : pasazhiry) {
        delete p;
    }

    return 0;
}
