#ifndef DETAIL_H
#define DETAIL_H

#include <iostream>
#include <vector>
#include <string>

struct detail_s_t {
    std::string name;
    std::string article;
    double price;
};

class Detail {
private:
    std::vector<detail_s_t> details;

public:
    Detail();
    ~Detail();

    void inputDetailData();
    void displayDetailData() const;
    void updateDetailByNumber();
    void deleteDetail();
    void clearDetails();
    void swapDetails();
    void insertDetailAtPosition();

    // Додаємо метод для додавання попередньо ініціалізованих деталей
    void addPredefinedDetail(const detail_s_t& det);
};

#endif // DETAIL_H
