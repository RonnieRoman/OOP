#ifndef BUS_H
#define BUS_H

#include "Passenger.h"

class Bus : public Passenger {
private:
    std::string name;
    int capacity;

public:
    Bus() = default;
    Bus(const std::string& name, int capacity) : name(name), capacity(capacity) {}

    void saveToFile(std::ofstream& ofs) const override {
        ofs << "Bus " << name << " " << capacity << std::endl;
    }

    void loadFromFile(std::ifstream& ifs) override {
        ifs >> name >> capacity;
    }

    // Реалізація методу display() для класу Bus
    void display() const override {
        std::cout << "Автобус: Назва = " << name << ", Місткість = " << capacity << std::endl;
    }
};

#endif // BUS_H
