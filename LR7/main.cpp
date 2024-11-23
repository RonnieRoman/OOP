#include "detail.h"

int main() {
    Detail detail;

    // Ініціалізація двох деталей для тестування
    detail_s_t detail1 = {"Деталь 1", "ART001", 100};
    detail_s_t detail2 = {"Деталь 2", "ART002", 200};

    // Додаємо ці деталі до списку
    detail.addPredefinedDetail(detail1);
    detail.addPredefinedDetail(detail2);

    detail.displayDetailData();

    detail.inputDetailData();
    detail.displayDetailData();

    detail.updateDetailByNumber();
    detail.displayDetailData();

    detail.deleteDetail();
    detail.displayDetailData();

    detail.swapDetails(); // Виклик обміну деталей місцями
    detail.displayDetailData();

    detail.insertDetailAtPosition(); // Вставка деталі після певного номера
    detail.displayDetailData();

    detail.clearDetails();
    detail.displayDetailData();

    return 0;
}
