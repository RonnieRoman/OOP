#ifndef DISPLAY_H
#define DISPLAY_H

#include "Pasazhyr.h"
#include "Poizd.h"
#include "Avtobus.h"
#include <iostream>

class Display {
public:
    void show(const Pasazhyr& p) {
        std::cout << "\nПеревезення: " << p.getName() << "\n"
                  << "Вартість: " << p.getCost() << "\n"
                  << "Тривалість: " << p.getDuration() << " годин\n";

        // Виведення кількості пасажирів залежно від типу об'єкта
        if (const auto* poizd = dynamic_cast<const Poizd*>(&p)) {
            std::cout << "Кількість пасажирів у поїзді: " << poizd->getPassengers() << std::endl;
        } else if (const auto* avtobus = dynamic_cast<const Avtobus*>(&p)) {
            std::cout << "Кількість пасажирів в автобусі: " << avtobus->getPassengers() << std::endl;
        }
    }
};

#endif
