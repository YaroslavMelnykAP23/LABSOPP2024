#include "FriendClass_Lab9.h"

void FriendClass::showDetails(const MarineAnimal& animal) {
    std::cout << "Деталі тварини:\n";
    animal.display();
}

void FriendClass::calculateStatistics(const std::vector<MarineAnimal*>& animals) {
    double totalLength = 0.0;
    int minAge = INT_MAX;
    int maxAge = INT_MIN;

    for (const auto& animal : animals) {
        totalLength += animal->length;
        if (animal->age < minAge) minAge = animal->age;
        if (animal->age > maxAge) maxAge = animal->age;
    }

    std::cout << "Загальна довжина всіх тварин: " << totalLength << " м\n";
    std::cout << "Мінімальний вік: " << minAge << " років\n";
    std::cout << "Максимальний вік: " << maxAge << " років\n";
}
