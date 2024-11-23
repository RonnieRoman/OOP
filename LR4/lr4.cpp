#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Detail {
private:
    string name;
    string article;
    double price;

public:
    // Конструктор за замовчуванням
    Detail() {}

    // Конструктор з параметрами
    Detail(string n, string a, double p) : name(n), article(a), price(p) {}

    // Метод для введення даних з перевіркою
    void inputDetail() {
        // Введення назви деталі з перевіркою на порожнє значення
        while (true) {
            cout << "Введіть назву деталі: ";
            getline(cin, name);
            if (name.empty()) {
                cout << "Назва деталі не може бути порожньою. Повторіть ввід.\n";
            }
            else {
                break;
            }
        }

        // Введення артикулу з перевіркою на порожнє значення
        while (true) {
            cout << "Введіть артикул деталі: ";
            getline(cin, article);
            if (article.empty()) {
                cout << "Артикул не може бути порожнім. Повторіть ввід.\n";
            }
            else {
                break;
            }
        }

        // Введення ціни з перевіркою на правильність введення та діапазон
        while (true) {
            cout << "Введіть ціну деталі: ";
            cin >> price;
            if (cin.fail() || price < 0) {
                cout << "Ціна повинна бути додатнім числом. Повторіть ввід.\n";
                cin.clear(); // очищаємо стан потоку
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ігноруємо залишок у потоці
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаємо буфер
                break;
            }
        }
    }

    // Метод для виведення даних
    void displayDetail() const {
        cout << "Назва деталі: " << name << endl;
        cout << "Артикул: " << article << endl;
        cout << "Ціна: " << price << " грн" << endl;
    }

    // Метод для зміни даних
    void setDetail(string n, string a, double p) {
        name = n;
        article = a;
        price = p;
    }
};

int main() {
    // Створення екземпляру класу з ініціалізацією
    Detail detail1("Гальмівний диск", "BRK123", 1500.50);

    // Створення іншого екземпляру класу без ініціалізації
    Detail detail2;

    // Введення даних для другого екземпляру
    cout << "Введіть дані для деталі 2:\n";
    detail2.inputDetail();

    // Виведення даних обох екземплярів
    cout << "\nДані деталі 1:\n";
    detail1.displayDetail();

    cout << "\nДані деталі 2:\n";
    detail2.displayDetail();

    return 0;
}
