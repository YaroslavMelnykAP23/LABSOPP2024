#include "Date_Lab10.h"
#include <iostream>
#include <vector>

// Сортування вибором
void selectionSort(std::vector<Date>& dates) {
    size_t n = dates.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (dates[j].getWeekday() < dates[minIndex].getWeekday()) {
                minIndex = j;
            }
        }
        std::swap(dates[i], dates[minIndex]);
    }
}

int main() {
    // Приклад дат
    std::vector<Date> dates = {
        Date(28, 11, 2024),
        Date(1, 12, 2024),
        Date(5, 12, 2024),
        Date(30, 11, 2024)
    };

    // Сортування за днем тижня
    selectionSort(dates);

    // Вивід відсортованих дат
    std::cout << "Відсортовані дати за днем тижня:\n";
    for (const auto& date : dates) {
        std::cout << date.toString() << "\n";
    }

    // Знаходження найближчої дати для кожного дня
    int targetWeekday = 5; //п'ятниця
    std::cout << "\nНайближчі дати до п'ятниці:\n";
    for (const auto& date : dates) {
        Date nearest = date + targetWeekday;
        std::cout << "для дати " << date.toString()
                  << " найближча дата: " << nearest.toString() << "\n";
    }

    return 0;
}
