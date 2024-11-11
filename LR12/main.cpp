#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "Passenger.h"
#include "Train.h"
#include "Bus.h"

// Функція для перевірки, чи рядок не порожній
bool isValidName(const std::string& name) {
    return !name.empty();
}

// Функція для перевірки, чи введено дійсне позитивне число
bool isValidPositiveNumber(const std::string& str) {
    if (str.empty()) return false; // Пустий рядок
    for (char c : str) {
        if (!isdigit(c)) { // Перевірка, що кожен символ - це цифра
            return false;
        }
    }
    return std::stoi(str) > 0;
}

// Функція для введення і перевірки числового вибору меню
int getMenuChoice() {
    std::string input;
    while (true) {
        std::cout << "\nМеню:\n1. Додати поїзд\n2. Додати автобус\n3. Зберегти дані\n4. Завантажити дані\n5. Вийти\n";
        std::getline(std::cin, input);

        if (isValidPositiveNumber(input)) {
            int choice = std::stoi(input);
            if (choice >= 1 && choice <= 5) {
                return choice;
            }
        }
        std::cout << "Невірний вибір. Введіть число від 1 до 5.\n";
    }
}

// Функція для введення і перевірки назви
std::string getValidatedName(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (isValidName(input)) {
            return input;
        } else {
            std::cout << "Назва не може бути порожньою. Спробуйте ще раз.\n";
        }
    }
}

// Функція для введення і перевірки числового значення
int getValidatedPositiveNumber(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (isValidPositiveNumber(input)) {
            return std::stoi(input);
        } else {
            std::cout << "Введіть дійсне позитивне число. Спробуйте ще раз.\n";
        }
    }
}

// Функція для збереження даних у файл
void saveToFile(const std::string& filename, const std::vector<Passenger*>& passengers) {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Помилка відкриття файлу для запису." << std::endl;
        return;
    }
    for (const auto& passenger : passengers) {
        passenger->saveToFile(ofs);
    }
    ofs.close();
    std::cout << "Дані успішно збережено у файл." << std::endl;
}

// Функція для завантаження даних з файлу
void loadFromFile(const std::string& filename, std::vector<Passenger*>& passengers) {
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Помилка відкриття файлу для читання." << std::endl;
        return;
    }

    std::string type;
    while (ifs >> type) {
        if (type == "Train") {
            Passenger* passenger = new Train();
            passenger->loadFromFile(ifs);
            passengers.push_back(passenger);
        } else if (type == "Bus") {
            Passenger* passenger = new Bus();
            passenger->loadFromFile(ifs);
            passengers.push_back(passenger);
        }
    }
    ifs.close();
    std::cout << "Дані успішно завантажено з файлу." << std::endl;

    // Вивід завантажених даних у термінал
    std::cout << "Завантажені дані:" << std::endl;
    for (const auto& passenger : passengers) {
        passenger->display();
    }
}

// Головна функція
int main() {
    std::vector<Passenger*> passengers;
    std::string filename = "passengers.txt";

    int option;
    do {
        option = getMenuChoice();

        switch (option) {
            case 1: {
                std::string name = getValidatedName("Введіть назву поїзда: ");
                int capacity = getValidatedPositiveNumber("Введіть місткість поїзда: ");
                passengers.push_back(new Train(name, capacity));
                break;
            }
            case 2: {
                std::string name = getValidatedName("Введіть назву автобуса: ");
                int capacity = getValidatedPositiveNumber("Введіть місткість автобуса: ");
                passengers.push_back(new Bus(name, capacity));
                break;
            }
            case 3:
                saveToFile(filename, passengers);
                break;
            case 4:
                loadFromFile(filename, passengers);
                break;
        }
    } while (option != 5);

    for (auto passenger : passengers) {
        delete passenger;
    }

    return 0;
}
