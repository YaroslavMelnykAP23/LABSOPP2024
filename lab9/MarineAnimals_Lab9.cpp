#include "MarineAnimals_Lab9.h"

MarineAnimal::MarineAnimal(std::string name, std::string habitat, double length, int age)
    : name(name), habitat(habitat), length(length), age(age) {}

MarineAnimal::~MarineAnimal() {}

void MarineAnimal::display() const {
    std::cout << "Назва: " << name << ", Середовище: " << habitat
              << ", Довжина: " << length << " м, Вік: " << age << " років\n";
}
