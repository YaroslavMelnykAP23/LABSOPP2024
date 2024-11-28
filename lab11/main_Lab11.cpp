#include "Fish_Lab11.h"    // Заголовок для класу Fish
#include "Mammals_Lab11.h" // Заголовок для класу Mammal
#include <vector>
#include <iostream>

int main() {
    std::vector<MarineAnimal*> animals; // Динамічний масив вказівників на базовий клас

    // Додавання тварин
    animals.push_back(new Fish("Акула", "Море", 6.5, "Гострі", "Морська"));
    animals.push_back(new Mammal("Дельфін", "Океан", 2.5, "Легені", 30));
    animals.push_back(new Mammal("Кит", "Океан", 15.0, "Легені", 70));

    // Виведення списку тварин
    std::cout << "Список морських тварин:\n";
    for (const auto& animal : animals) {
        animal->display();
        std::cout << "----------------------\n";
    }

    // Обчислення загальної довжини
    double totalLength = 0.0;
    for (const auto& animal : animals) {
        totalLength += animal->getLength(); // Віртуальний метод getLength()
    }

    std::cout << "Загальна довжина всіх морських тварин: " << totalLength << " м\n";

    // Видалення виділеної пам'яті
    for (auto& animal : animals) {
        delete animal;
    }

    return 0;
}
