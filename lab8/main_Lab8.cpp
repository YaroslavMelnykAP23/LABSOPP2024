#include "Fish_Lab8.h"
#include "Mammals_Lab8.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<MarineAnimal*> animals;

    // Додавання тварин
    animals.push_back(new Fish("Акула", "Море", 6.5, "Гострі", "Морська"));
    animals.push_back(new Mammal("Дельфін", "Океан", 2.5, "Легені", 30));
    animals.push_back(new Mammal("Кит", "Океан", 15.0, "Легені", 70));

    std::cout << "Список морських тварин:\n";
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
