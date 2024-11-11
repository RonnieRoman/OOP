#ifndef BUS_H
#define BUS_H

#include "Passenger.h"

class Bus : public Passenger {
private:
    std::string busNumber;
public:
    Bus(std::string name = "", int ticketNumber = 0, std::string busNumber = "")
        : Passenger(name, ticketNumber), busNumber(busNumber) {}

    void input() override {
        Passenger::input();
        std::cout << "Введіть номер автобуса: ";
        std::getline(std::cin, busNumber);
        while (busNumber.empty()) {
            std::cout << "Номер автобуса не може бути порожнім. Введіть знову: ";
            std::getline(std::cin, busNumber);
        }
    }

    void display() const override {
        Passenger::display();
        std::cout << "Номер автобуса: " << busNumber << std::endl;
    }
};

#endif
