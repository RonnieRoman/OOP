#include <iostream>
#include <math.h>  

double First(double a, double x) {
    return cbrt(pow(a, 2) + pow(3 * x, 2));
}

double Second(double a, double b, double x) {
    return pow(log(abs(x - b)), 2);
}

double Third(double a, double b, double x) {
    double e = 2.718;
    return pow(e, a * x) - pow(x, 4);
}

void calculateResult(double a, double b, double x) {
    double result;

    if (x < b) {
        result = First(a, x);
    }
    else if (b <= x && x <= b + 1) {
        // Перевірка на випадок, коли x = b
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

int main() {
    double a;
    double b;
    double x;

    std::cout << "Введіть число a: ";
    std::cin >> a;
    std::cout << "Введіть число b: ";
    std::cin >> b;
    std::cout << "Введіть число x: ";
    std::cin >> x;

    calculateResult(a, b, x);

    return 0;
}
