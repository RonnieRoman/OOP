#include "detail.h"
#include "detail.cpp"

int main() {
    // Створення об'єкту класу DetailManager
    DetailManager manager;

    // Додати нову деталь
    manager.inputDetails();

    // Вивести всі деталі
    manager.displayDetails();

    // Фільтрувати деталі
    manager.filterDetails();

    // Оновити деталь за ID
    manager.updateDetailById();

    // Видалити деталь за ID
    manager.deleteDetailById();

    return 0;
}
