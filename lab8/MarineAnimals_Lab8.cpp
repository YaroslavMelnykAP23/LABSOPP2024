#include "MarineAnimals_Lab8.h"

MarineAnimal::MarineAnimal(std::string name, std::string habitat, double length)
    : name(name), habitat(habitat), length(length) {}

MarineAnimal::~MarineAnimal() {}

void MarineAnimal::setName(const std::string& name) {
    this->name = name;
}

void MarineAnimal::setHabitat(const std::string& habitat) {
    this->habitat = habitat;
}

void MarineAnimal::setLength(double length) {
    if (length <= 0) {
        std::cerr << "Довжина повинна бути позитивною!\n";
        return;
    }
    this->length = length;
}

std::string MarineAnimal::getName() const {
    return name;
}

std::string MarineAnimal::getHabitat() const {
    return habitat;
}

double MarineAnimal::getLength() const {
    return length;
}

void MarineAnimal::display() const {
    std::cout << "Назва: " << name << ", Середовище: " << habitat
              << ", Довжина: " << length << " м\n";
}
