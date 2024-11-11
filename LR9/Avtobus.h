#ifndef AVTOBUS_H
#define AVTOBUS_H

#include "Pasazhiry.h"

class Avtobus : public Pasazhiry {
private:
    int passengers; // Кількість пасажирів

public:
    Avtobus(std::string n = "", double c = 0.0, int d = 0, int p = 0);
    ~Avtobus();

    int getPassengers() const;
    void setPassengers(int p);

    void display() const override;
    void input() override;
};

#endif
