#ifndef TRAIN_H
#define TRAIN_H

#include "Passenger.h"

class Train : public Passenger {
private:
    std::string trainNumber;
public:
    Train(std::string name = "", int ticketNumber = 0, std::string trainNumber = "")
        : Passenger(name, ticketNumber), trainNumber(trainNumber) {}

    void input() override {
        Passenger::input();
        std::cout << "Введіть номер потяга: ";
        std::getline(std::cin, trainNumber);
        while (trainNumber.empty()) {
            std::cout << "Номер потяга не може бути порожнім. Введіть знову: ";
            std::getline(std::cin, trainNumber);
        }
    }

    void display() const override {
        Passenger::display();
        std::cout << "Номер потяга: " << trainNumber << std::endl;
    }
};

#endif
