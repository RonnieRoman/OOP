#include <iostream>
#include <vector>
#include <limits>
#include "Pasazhyr.h"
#include "Poizd.h"
#include "Avtobus.h"
#include "display.h"

int main() {
    std::vector<Pasazhyr*> pasazhyrList;
    int poizdCount = 0, avtobusCount = 0;

    // Введення кількості поїздів
    while (true) {
        std::cout << "Скільки поїздів ви хочете додати? ";
        std::cin >> poizdCount;
        if (std::cin.fail() || poizdCount <= 0) {
            std::cout << "Введіть дійсне ціле число більше 0.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Введення кількості автобусів
    while (true) {
        std::cout << "Скільки автобусів ви хочете додати? ";
        std::cin >> avtobusCount;
        if (std::cin.fail() || avtobusCount <= 0) {
            std::cout << "Введіть дійсне ціле число більше 0.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Введення перевезень
    for (int i = 0; i < poizdCount; i++) {
        std::cout << "\nВведення даних для поїзда №" << (i + 1) << ":\n";
        Poizd* p = new Poizd();
        p->input();
        pasazhyrList.push_back(p);
    }

    for (int i = 0; i < avtobusCount; i++) {
        std::cout << "\nВведення даних для автобуса №" << (i + 1) << ":\n";
        Avtobus* a = new Avtobus();
        a->input();
        pasazhyrList.push_back(a);
    }

    Display display;

    // Виведення перевезень
    for (const auto& p : pasazhyrList) {
        std::cout << "\nТип перевезення: " << p->getType() << "\n";  // Виводимо тип перевезення
        display.show(*p);
        if (auto* poizd = dynamic_cast<Poizd*>(p)) {
            display.showPassengers(*poizd);
        } else if (auto* avtobus = dynamic_cast<Avtobus*>(p)) {
            display.showPassengers(*avtobus);
        }
        std::cout << "---------------------\n";
    }

    // Обчислення загальної кількості пасажирів, середньої вартості та середньої тривалості
    int totalPassengers = 0;
    double totalCost = 0.0;
    int totalDuration = 0;

    for (const auto& p : pasazhyrList) {
        totalCost += p->getCost();
        totalDuration += p->getDuration();
        
        if (auto* poizd = dynamic_cast<Poizd*>(p)) {
            totalPassengers += poizd->getPassengers();
        } else if (auto* avtobus = dynamic_cast<Avtobus*>(p)) {
            totalPassengers += avtobus->getPassengers();
        }
    }

    // Виведення статистики
    int totalCount = pasazhyrList.size();
    double averageCost = totalCount > 0 ? totalCost / totalCount : 0;
    double averageDuration = totalCount > 0 ? static_cast<double>(totalDuration) / totalCount : 0;

    std::cout << "\nЗагальна кількість пасажирів: " << totalPassengers << "\n";
    std::cout << "Середня вартість перевезення: " << averageCost << "\n";
    std::cout << "Середня тривалість перевезення: " << averageDuration << " годин\n";

    // Очищення пам'яті
    for (auto p : pasazhyrList) {
        delete p;
    }

    return 0;
}
