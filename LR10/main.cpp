#include <iostream>
#include "RealNumber.h"

int main() {
    // Масив дійсних чисел
    RealNumber arr[] = { RealNumber(4.5), RealNumber(3.14), RealNumber(5.99), RealNumber(2.25), RealNumber(3.21), RealNumber(3.01) };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "До сортування:" << std::endl;
    for (int i = 0; i < size; ++i) {
        arr[i].print();
    }

    // Сортуємо масив за спаданням
    RealNumber::sortArray(arr, size);

    std::cout << "\nПісля сортування:" << std::endl;
    for (int i = 0; i < size; ++i) {
        arr[i].print();
    }

    // Демонстрація оператора []
    std::cout << "\nДробова частина для arr[0]: " << arr[0][0] << std::endl;

    return 0;
}
