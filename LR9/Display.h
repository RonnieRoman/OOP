#ifndef DISPLAY_H
#define DISPLAY_H

#include "Poizd.h"
#include "Avtobus.h"
#include <iostream>

class Display {
public:
    void show(const Pasazhyr& p) {
        std::cout << "\nПеревезення: " << p.getName() << "\n"
                  << "Вартість: " << p.getCost() << "\n"
                  << "Тривалість: " << p.getDuration() << " годин\n";
    }

    void showPassengers(const Poizd& poizd) {
        std::cout << "Кількість пасажирів у поїзді: " << poizd.getPassengers() << std::endl;
    }

    void showPassengers(const Avtobus& avtobus) {
        std::cout << "Кількість пасажирів в автобусі: " << avtobus.getPassengers() << std::endl;
    }
};

#endif
