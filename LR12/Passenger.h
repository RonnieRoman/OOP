#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <fstream>
#include <string>

class Passenger {
public:
    virtual void saveToFile(std::ofstream& ofs) const = 0;
    virtual void loadFromFile(std::ifstream& ifs) = 0;
    
    // Додаємо віртуальний метод display() у базовий клас
    virtual void display() const = 0; 

    virtual ~Passenger() = default;
};

#endif // PASSENGER_H
