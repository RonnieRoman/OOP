#ifndef POIZD_H
#define POIZD_H

#include "Pasazhyr.h"

class Display; // Декларація класу Display

class Poizd : public Pasazhyr {
private:
    int passengers;

public:
    Poizd(std::string n = "", double c = 0.0, int d = 0, int p = 0);
    ~Poizd();

    friend class Display; // Дружній клас Display

    void display() const override;
    void input() override;
    int getPassengers() const { return passengers; }
    std::string getType() const override { return "Поїзд"; }
};

#endif
