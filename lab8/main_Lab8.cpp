#include "Fish_Lab8.h"
#include "Mammals_Lab8.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<MarineAnimal*> animals;

    // Додавання акули через введення даних
    Fish* shark = new Fish("", "", 0.0, "", "");
    shark->inputData();
    animals.push_back(shark);

    // Додавання інших морських тварин
    animals.push_back(new Mammal("Дельфін", "Океан", 2.5, "Легені", 30));
    animals.push_back(new Mammal("Кит", "Океан", 15.0, "Легені", 70));

    // Вивід списку тварин
    std::cout << "\nСписок морських тварин:\n";
    for (const auto& animal : animals) {
        animal->display();
        std::cout << "----------------------\n";
    }

    // Обчислення загальної довжини
    double totalLength = 0.0;
    for (const auto& animal : animals) {
        totalLength += animal->getLength();
    }

    std::cout << "Загальна довжина всіх морських тварин: " << totalLength << " м\n";

    // Видалення виділеної пам'яті
    for (auto& animal : animals) {
        delete animal;
    }

    return 0;
}
