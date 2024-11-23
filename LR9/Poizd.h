#ifndef POIZD_H
#define POIZD_H

#include "Pasazhyr.h"

class Poizd : public Pasazhyr {
private:
    int passengers; // Кількість пасажирів

public:
    Poizd(std::string n = "", double c = 0.0, int d = 0, int p = 0);
    ~Poizd();

    friend class Display;

    void display() const override;
    void input() override;
    int getPassengers() const { return passengers; }

    std::string getType() const override { return "Поїзд"; } // Визначаємо тип перевезення
};

#endif
