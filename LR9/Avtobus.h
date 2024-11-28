#ifndef AVTOBUS_H
#define AVTOBUS_H

#include "Pasazhyr.h"

class Display; // Декларація класу Display

class Avtobus : public Pasazhyr {
private:
    int passengers;

public:
    Avtobus(std::string n = "", double c = 0.0, int d = 0, int p = 0);
    ~Avtobus();

    friend class Display; // Дружній клас Display

    void display() const override;
    void input() override;
    int getPassengers() const { return passengers; }
    std::string getType() const override { return "Автобус"; }
};

#endif
