#ifndef POIZD_H
#define POIZD_H

#include "Pasazhiry.h"

class Poizd : public Pasazhiry {
private:
    int passengers; // Кількість пасажирів

public:
    Poizd(std::string n = "", double c = 0.0, int d = 0, int p = 0);
    ~Poizd();

    int getPassengers() const;
    void setPassengers(int p);

    void display() const override;
    void input() override; // Метод для введення даних
};

#endif
