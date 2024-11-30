#include "MarineAnimals_Lab11.h"

// Конструктор
MarineAnimal::MarineAnimal(std::string name, std::string habitat, double length)
    : name(name), habitat(habitat), length(length) {}

// Деструктор
MarineAnimal::~MarineAnimal() {}

// Сеттер для імені
void MarineAnimal::setName(const std::string& name) {
    this->name = name;
}

// Сеттер для середовища існування
void MarineAnimal::setHabitat(const std::string& habitat) {
    this->habitat = habitat;
}

// Сеттер для довжини
void MarineAnimal::setLength(double length) {
    if (length <= 0) {
        std::cerr << "Довжина повинна бути позитивною!\n";
        return;
    }
    this->length = length;
}

// Геттер для імені
std::string MarineAnimal::getName() const {
    return name;
}

// Геттер для середовища існування
std::string MarineAnimal::getHabitat() const {
    return habitat;
}

// Геттер для довжини
double MarineAnimal::getLength() const {
    return length;
}

// Виведення інформації про морську тварину
void MarineAnimal::display() const {
    std::cout << "Назва: " << name << ", Середовище: " << habitat
              << ", Довжина: " << length << " м\n";
}
