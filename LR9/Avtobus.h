#ifndef AVTOBUS_H
#define AVTOBUS_H

#include "Pasazhyr.h"

class Avtobus : public Pasazhyr {
private:
    int passengers;

public:
    Avtobus(std::string n = "", double c = 0.0, int d = 0, int p = 0);
    ~Avtobus();

    friend class Display;

    void display() const override;
    void input() override;
    int getPassengers() const { return passengers; }

    std::string getType() const override { return "Автобус"; } // Визначаємо тип перевезення
};

#endif
