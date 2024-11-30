#include "Date_Lab10.h"
#include <iostream>
#include <vector>

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
    std::vector<Date> dates;

    // Введення дат з клавіатури
    int numDates;
    std::cout << "Скільки дат потрібно ввести? ";
    std::cin >> numDates;

    for (int i = 0; i < numDates; ++i) {
        Date date;
        while (!date.inputFromKeyboard()) {
            std::cout << "Повторіть спробу вводу дати.\n";
        }
        dates.push_back(date);
    }

    selectionSort(dates);

    std::cout << "Відсортовані дати за днем тижня:\n";
    for (const auto& date : dates) {
        std::cout << date.toString() << "\n";
    }

    int targetWeekday;
    std::cout << "Введіть цільовий день тижня (0 - неділя, ..., 6 - субота): ";
    std::cin >> targetWeekday;

    std::cout << "\nНайближчі дати до цільового дня тижня:\n";
    for (const auto& date : dates) {
        Date nearest = date + targetWeekday;
        std::cout << "Для дати " << date.toString()
                  << " найближча дата: " << nearest.toString() << "\n";
    }

    return 0;
}
