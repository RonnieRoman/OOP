#include <iostream>
#include <cmath>
#include <limits>

// Функції обчислення
double First(double a, double x) {
    return cbrt(pow(a, 2) + 3 * pow(x, 2));
}

double Second(double a, double b, double x) {
    return pow(log(abs(x - b)), 2);
}

double Third(double a, double b, double x) {
    const double e = 2.718;
    return pow(e, a * x) - pow(x, 4);
}

// Основна функція для обчислення результату
void calculateResult(double a, double b, double x) {
    double result;

    if (x < b) {
        result = First(a, x);
    }
    else if (b <= x && x <= b + 1) {
        if (x == b) {
            std::cout << "Результат: нескінченність (оскільки log(0) → ∞ при x = b)" << std::endl;
            return;
        }
        result = Second(a, b, x);
    }
    else if (x > b + 1) {
        result = Third(a, b, x);
    }

    std::cout << "Відповідь: " << result << std::endl;
}

// Функція для безпечного вводу чисел
double safeInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear(); // Скидання стану потоку
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Пропуск некоректного вводу
            std::cout << "Помилка вводу! Будь ласка, введіть число.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення зайвого вводу
            return value;
        }
    }
}

int main() {
    // Вводимо змінні з перевіркою
    double a = safeInput("Введіть число a: ");
    double b = safeInput("Введіть число b: ");
    double x = safeInput("Введіть число x: ");

    calculateResult(a, b, x);

    return 0;
}
