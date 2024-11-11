#ifndef TRAIN_H
#define TRAIN_H

#include "Passenger.h"

class Train : public Passenger {
private:
    std::string name;
    int capacity;

public:
    Train() = default;
    Train(const std::string& name, int capacity) : name(name), capacity(capacity) {}

    void saveToFile(std::ofstream& ofs) const override {
        ofs << "Train " << name << " " << capacity << std::endl;
    }

    void loadFromFile(std::ifstream& ifs) override {
        ifs >> name >> capacity;
    }

    // Реалізація методу display() для класу Train
    void display() const override {
        std::cout << "Поїзд: Назва = " << name << ", Місткість = " << capacity << std::endl;
    }
};

#endif // TRAIN_H
