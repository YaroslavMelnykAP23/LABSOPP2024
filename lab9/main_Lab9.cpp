#include "FriendClass_Lab9.h"

int main() {
    std::vector<MarineAnimal*> animals;

    animals.push_back(new Fish("Акула", "Море", 6.5, 10, "Гострі", "Морська"));
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
