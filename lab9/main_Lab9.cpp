#include "FriendClass_Lab9.h"
#include <windows.h>
#include <iostream>
int main() {
    std::vector<MarineAnimal*> animals;

    Fish* fish1 = new Fish("", "", 0.0, 0, "", "");
    fish1->inputData();  // Викликаємо метод вводу даних для риби
    animals.push_back(fish1);

    // Інші тварини (дельфін, кит) залишаються без змін
    animals.push_back(new Mammal("Дельфін", "Океан", 2.5, 5, "Легені", 30));
    animals.push_back(new Mammal("Кит", "Океан", 15.0, 50, "Легені", 70));

    FriendClass friendClass;

    std::cout << "Деталі тварин:\n";
    for (const auto& animal : animals) {
        friendClass.showDetails(*animal);
        std::cout << "----------------------\n";
    }

    friendClass.calculateStatistics(animals);

    for (auto& animal : animals) {
        delete animal;
    }

    return 0;
}
