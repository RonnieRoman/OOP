#include "detail.h"
#include <limits>

Detail::Detail() {}

Detail::~Detail() {}

void Detail::inputDetailData() {
    int numberOfDetails;
    
    // Запит на введення кількості деталей
    while (true) {
        std::cout << "Введіть кількість деталей для додавання: ";
        std::cin >> numberOfDetails;

        if (std::cin.fail() || numberOfDetails <= 0) {
            std::cout << "Кількість деталей має бути числом більше 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    for (int i = 0; i < numberOfDetails; ++i) {
        detail_s_t det;

        // Перевірка назви
        while (true) {
            std::cout << "Введіть назву деталі " << (i + 1) << ": ";
            std::getline(std::cin, det.name);
            if (!det.name.empty()) {
                break;
            } else {
                std::cout << "Назва не може бути порожньою. Спробуйте ще раз.\n";
            }
        }

        // Перевірка артикулу
        while (true) {
            std::cout << "Введіть артикул деталі: ";
            std::getline(std::cin, det.article);
            if (!det.article.empty()) {
                break;
            } else {
                std::cout << "Артикул не може бути порожнім. Спробуйте ще раз.\n";
            }
        }

        // Перевірка ціни
        while (true) {
            std::string priceInput;
            std::cout << "Введіть ціну деталі: ";
            std::getline(std::cin, priceInput);

            // Перевірка, чи введене значення є числом
            try {
                det.price = std::stod(priceInput);
                if (det.price < 0) {
                    std::cout << "Ціна має бути більше або рівна 0. Спробуйте ще раз.\n";
                } else {
                    break;
                }
            } catch (const std::invalid_argument&) {
                std::cout << "Ціна має бути числом. Спробуйте ще раз.\n";
            } catch (const std::out_of_range&) {
                std::cout << "Введене число занадто велике. Спробуйте ще раз.\n";
            }
        }

        // Додавання деталі в список
        details.push_back(det);
    }
}

void Detail::addPredefinedDetail(const detail_s_t& det) {
    details.push_back(det);
}

void Detail::displayDetailData() const {
    if (details.empty()) {
        std::cout << "Немає даних про деталі.\n";
        return;
    }

    std::cout << "\nДані про деталі:\n";
    for (size_t i = 0; i < details.size(); ++i) {
        std::cout << "Деталь " << (i + 1) << ": "
                  << "Назва: " << details[i].name
                  << ", Артикул: " << details[i].article
                  << ", Ціна: " << details[i].price << "\n";
    }
}

void Detail::updateDetailByNumber() {
    int detNumber;
    while (true) {
        std::cout << "Введіть номер деталі для оновлення: ";
        std::cin >> detNumber;
        if (std::cin.fail() || detNumber < 1 || detNumber > details.size()) {
            std::cout << "Некоректний номер. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    detail_s_t& det = details[detNumber - 1];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Оновлення даних для деталі " << detNumber << ":\n";

    std::cout << "Нова назва (залиште порожнім для пропуску): ";
    std::string newName;
    std::getline(std::cin, newName);
    if (!newName.empty()) {
        det.name = newName;
    }

    std::cout << "Новий артикул (залиште порожнім для пропуску): ";
    std::string newArticle;
    std::getline(std::cin, newArticle);
    if (!newArticle.empty()) {
        det.article = newArticle;
    }

    while (true) {
        std::cout << "Нова ціна (залиште порожнім для пропуску): ";
        std::string newPriceInput;
        std::getline(std::cin, newPriceInput);
        if (newPriceInput.empty()) break;

        try {
            double newPrice = std::stod(newPriceInput);
            if (newPrice < 0) {
                std::cout << "Ціна має бути більше або рівне 0. Спробуйте ще раз.\n";
            } else {
                det.price = newPrice;
                break;
            }
        } catch (std::invalid_argument&) {
            std::cout << "Некоректне значення. Спробуйте ще раз.\n";
        }
    }

    std::cout << "Дані деталі оновлено.\n";
}

void Detail::deleteDetail() {
    int detNumber;
    while (true) {
        std::cout << "Введіть номер деталі для видалення: ";
        std::cin >> detNumber;
        if (std::cin.fail() || detNumber < 1 || detNumber > details.size()) {
            std::cout << "Некоректний номер. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    details.erase(details.begin() + detNumber - 1);
    std::cout << "Деталь видалено.\n";
}

void Detail::swapDetails() {
    int first, second;
    std::cout << "Введіть номери двох деталей для обміну: ";
    std::cin >> first >> second;

    if (first >= 1 && first <= details.size() && second >= 1 && second <= details.size() && first != second) {
        std::swap(details[first - 1], details[second - 1]);
        std::cout << "Деталі обміняно місцями.\n";
    } else {
        std::cout << "Некоректні номери для обміну. Спробуйте ще раз.\n";
    }
}

void Detail::insertDetailAtPosition() {
    int position;
    detail_s_t newDetail;

    while (true) {
        std::cout << "Введіть номер деталі, після якої вставити нову: ";
        std::cin >> position;
        if (std::cin.fail() || position < 0 || position > details.size()) {
            std::cout << "Некоректний номер. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Введення даних нової деталі
    std::cout << "Введіть назву нової деталі: ";
    std::getline(std::cin, newDetail.name);

    std::cout << "Введіть артикул нової деталі: ";
    std::getline(std::cin, newDetail.article);

    while (true) {
        std::cout << "Введіть ціну нової деталі: ";
        std::cin >> newDetail.price;
        if (std::cin.fail() || newDetail.price < 0) {
            std::cout << "Ціна має бути числом більше або рівне 0. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    details.insert(details.begin() + position, newDetail);
    std::cout << "Деталь вставлено.\n";
}

void Detail::clearDetails() {
    details.clear();
    std::cout << "Всі дані очищено.\n";
}
