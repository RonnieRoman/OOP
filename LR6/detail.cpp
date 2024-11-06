#include "detail.h"
#include <limits>

// Конструктор за замовчуванням, де ініціалізовано дві деталі
DetailManager::DetailManager() {
    details[0] = {1, "DetailA", 100.0};
    details[1] = {2, "DetailB", 200.0};
    nextId = 3; // Наступний ID для нового товару
    details[2] = {0, "Unknown", 0.0}; // Порожнє місце для нової деталі
}

// Деструктор
DetailManager::~DetailManager() {
    cout << "Залишкові деталі після завершення роботи:" << endl;
    displayDetails(); // Виведемо список деталей, які залишились
}

// Метод для введення нових деталей
void DetailManager::inputDetails() {
    for (int i = 0; i < SIZE; i++) {
        if (details[i].id == 0) {
            details[i].id = nextId++;
            cout << "Введіть назву деталі (ID " << details[i].id << "): ";
            string name;
            getline(cin, name);
            while (name.empty()) {
                cout << "Назва не може бути порожньою. Введіть ще раз: ";
                getline(cin, name);
            }
            details[i].name = name;

            double tempPrice;
            while (true) {
                cout << "Введіть ціну деталі: ";
                if (!(cin >> tempPrice)) {
                    cout << "Невірне значення ціни. Введіть числове значення.\n";
                    cin.clear();  // Очищаємо стан потоку після помилки
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очищаємо залишки в буфері
                    continue;  // Продовжуємо цикл, щоб дати можливість ввести знову
                }
                if (tempPrice < 0) {
                    cout << "Ціна не може бути від'ємною. Спробуйте ще раз." << endl;
                    continue;  // Продовжуємо цикл, якщо ціна від'ємна
                }
                break;  // Якщо введено коректну ціну, вийдемо з циклу
            }

            details[i].price = tempPrice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаємо буфер після вводу числа
            break;
        }
    }
}



// Метод для виведення всіх деталей
void DetailManager::displayDetails() const {
    cout << "\nДеталі:" << endl;
    for (const auto& detail : details) {
        if (detail.id != 0) {
            cout << "ID: " << detail.id << ", Назва: " << detail.name << ", Ціна: " << detail.price << " грн" << endl;
        }
    }
}

// Метод для фільтрації деталей за назвою або ціною
void DetailManager::filterDetails() const {
    int choice;
    cout << "Фільтрувати за: 1 - Назвою, 2 - Ціною. Виберіть: ";

    // Перевірка на коректність введеного вибору
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Невірний вибір. Введіть 1 для фільтрації за назвою або 2 для ціною: ";
        cin.clear();  // Очищаємо стан потоку після неправильного введення
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очищаємо залишки в буфері
    }

    if (choice == 1) {
        string nameFilter;
        cout << "Введіть назву для фільтрації: ";
        cin.ignore(); // Очищення залишкового символа після вибору
        getline(cin, nameFilter);

        while (nameFilter.empty()) {
            cout << "Назва не може бути порожньою. Введіть ще раз: ";
            getline(cin, nameFilter);
        }

        bool found = false;
        for (const auto& detail : details) {
            if (detail.id != 0 && detail.name == nameFilter) {
                cout << "ID: " << detail.id << ", Назва: " << detail.name << ", Ціна: " << detail.price << " грн" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Не знайдено деталей з назвою: " << nameFilter << "." << endl;
        }

    } else if (choice == 2) {
        double priceFilter;
        cout << "Введіть мінімальну ціну для фільтрації: ";

        // Перевірка на коректність введення ціни
        while (true) {
            if (!(cin >> priceFilter)) {
                cout << "Невірне значення ціни. Спробуйте ще раз: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очищаємо залишки в буфері
            } else if (priceFilter < 0) {
                cout << "Ціна не може бути від'ємною. Введіть ще раз: ";
            } else {
                break;  // Якщо введено коректну ціну, виходимо з циклу
            }
        }

        bool found = false;
        for (const auto& detail : details) {
            if (detail.id != 0 && detail.price >= priceFilter) {
                cout << "ID: " << detail.id << ", Назва: " << detail.name << ", Ціна: " << detail.price << " грн" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Не знайдено деталей з ціною більше " << priceFilter << " грн." << endl;
        }

    } else {
        cout << "Невірний вибір!" << endl;
        filterDetails(); // Перезапускаємо фільтрацію при неправильному виборі
    }
}


// Метод для оновлення даних про деталь за ID
void DetailManager::updateDetailById() {
    int id;
    cout << "Введіть ID деталі, яку потрібно оновити: ";
    
    // Перевірка, чи введено правильне число (ID)
    while (!(cin >> id)) {
        cout << "Введено некоректне значення. Будь ласка, введіть числове значення ID: ";
        cin.clear();  // Очищаємо стан потоку після неправильного введення
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очищаємо залишки в буфері
    }

    int index = findDetailIndexById(id);
    if (index == -1) {
        cout << "Деталь з таким ID не знайдено." << endl;
        return;
    }

    cout << "Оновлення деталі ID: " << details[index].id << endl;
    cout << "Введіть нову назву: ";
    string newName;
    cin.ignore(); // Очищаємо буфер після вводу числа
    getline(cin, newName);

    while (newName.empty()) {
        cout << "Назва не може бути порожньою. Введіть ще раз: ";
        getline(cin, newName);
    }

    details[index].name = newName;

    double newPrice;
    do {
        cout << "Введіть нову ціну: ";
        if (!(cin >> newPrice)) {
            cout << "Невірне значення ціни. Введіть числове значення.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (!isValidPrice(newPrice)) {
            cout << "Ціна не може бути від'ємною. Спробуйте ще раз." << endl;
        }
    } while (!isValidPrice(newPrice) || !(cin >> newPrice)); // Повторюємо введення, поки не буде правильно введена ціна

    details[index].price = newPrice;
    cout << "Дані оновлено." << endl;
}

// Метод для видалення деталі за ID
void DetailManager::deleteDetailById() {
    int id;
    cout << "Введіть ID деталі, яку потрібно видалити: ";
    
    // Перевірка, чи введено правильне число (ID)
    while (!(cin >> id)) {
        cout << "Введено некоректне значення. Будь ласка, введіть числове значення ID: ";
        cin.clear();  // Очищаємо стан потоку після неправильного введення
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очищаємо залишки в буфері
    }

    int index = findDetailIndexById(id);
    if (index == -1) {
        cout << "Деталь з таким ID не знайдено." << endl;
        return;
    }

    details[index] = {0, "Unknown", 0.0}; // Заміна на порожнє значення
    cout << "Деталь ID " << id << " видалено." << endl;

    // Виведемо всі деталі після видалення
    cout << "Оновлений список деталей:" << endl;
    displayDetails();
}


// Перевірка валідності ціни
bool DetailManager::isValidPrice(double price) {
    return price >= 0;
}

// Метод для пошуку індексу деталі за ID
int DetailManager::findDetailIndexById(int id) const {
    for (int i = 0; i < SIZE; i++) {
        if (details[i].id == id) {
            return i;
        }
    }
    return -1; // Якщо деталь не знайдено
}
