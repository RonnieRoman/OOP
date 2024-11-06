#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Detail {
private:
    string name;
    string article;
    double price;

public:
    // Конструктор за замовчуванням і з параметрами
    Detail(string detName = "Unknown", string detArticle = "N/A", double detPrice = 0.0)
        : name(detName), article(detArticle), price(detPrice) {}

    // Метод для введення даних
    void input() {
        cout << "Введіть назву деталі: ";
        getline(cin,name);
        cout << "Введіть артикул деталі: ";
        getline(cin, article);

        // Введення і перевірка ціни
        do {
            cout << "Введіть ціну деталі: ";
            cin >> price;
            if (price < 0) {
                cout << "Помилка. Ціна не може бути від'ємною. Спробуйте ще раз." << endl;
            }
        } while (price < 0);  // повторювати, поки не введено коректну ціну
    }

    // Метод для виведення даних
    void display() const {
        cout << "Назва: " << name << ", Артикул: " << article << ", Ціна: " << price << " грн" << endl;
    }

    // Геттери для критеріїв
    double getPrice() const {
        return price;
    }

    string getArticle() const {
        return article;
    }
};

// Функція для виведення деталей за ціновим критерієм
void displayByPrice(const vector<Detail>& details, double priceCriteria) {
    bool found = false;
    for (const auto& detail : details) {
        if (detail.getPrice() > priceCriteria) {
            detail.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Не знайдено деталей з ціною більшою за " << priceCriteria << " грн." << endl;
    }
}

// Функція для виведення деталей за артикулом
void displayByArticle(const vector<Detail>& details, const string& articleCriteria) {
    bool found = false;
    for (const auto& detail : details) {
        if (detail.getArticle() == articleCriteria) {
            detail.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Не знайдено деталей з артикулом: " << articleCriteria << "." << endl;
    }
}

int main() {
    // Створюємо кілька екземплярів класу
    Detail detail1("Шестерня", "G123", 750.0);
    Detail detail2("Гальмівний диск", "BRK456", 1500.0);
    Detail detail3; // Використання конструктора за замовчуванням

    // Виведення даних про деталі
    detail1.display();
    detail2.display();
    detail3.input(); // Введення даних для третьої деталі
    detail3.display();

    // Додавання деталей у список
    vector<Detail> details = { detail1, detail2, detail3 };

    // Вибір фільтру
    int choice;
    bool validChoice = false;  // прапорець для перевірки коректного вибору

    while (!validChoice) {
        cout << "Фільтрувати за: 1 - Ціною, 2 - Артикулом. Виберіть: ";
        cin >> choice;

        if (choice == 1) {
            // Фільтрація за ціною
            double priceCriteria;
            cout << "Введіть мінімальну ціну для фільтру: ";
            cin >> priceCriteria;
            displayByPrice(details, priceCriteria);
            validChoice = true;
        }
        else if (choice == 2) {
            // Фільтрація за артикулом
            string articleCriteria;
            cout << "Введіть артикул для фільтру: ";
            cin >> articleCriteria;
            displayByArticle(details, articleCriteria);
            validChoice = true;
        }
        else {
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
        }
    }

    return 0;
}
