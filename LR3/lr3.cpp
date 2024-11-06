#include <iostream>
#include <math.h>  

using namespace std;

double calculate(double a, double b, double x) {
    return (cbrt(a * x) + b) / (0.25 * pow(log(a * x), 2));
}

void Values(double x1, double x2, double h, double a, double b, double& dob, int& count) {
    for (double x = x1; x <= x2; x += h) {
        double y = calculate(a, b, x);

        if (y < 10) {
            dob *= y;
            count++;
        }
        cout << "y = " << y << "\n";
    }

    if (count > 0) {
        cout << "Добуток значень y < 10: " << dob << endl;
        cout << "Кількість значень y < 10: " << count << endl;
    } else {
        cout << "Немає жодного значення y, яке менше за 10." << endl;
    }
}

int main() {
    double x1 = 10.5;
    double x2 = 28.5;
    double h = 2;
    double a = 0.3;
    double b = 9.5;
    double dob = 1;
    int count = 0;

    Values(x1, x2, h, a, b, dob, count);

    return 0;
}
