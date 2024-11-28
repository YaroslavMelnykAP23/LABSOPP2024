#include "Mammals_Lab11.h"

// Конструктор з ініціалізацією базового класу
Mammal::Mammal(std::string name, std::string habitat, double length,
               std::string breathingType, int lifespan)
    : MarineAnimal(name, habitat, length), breathingType(breathingType), lifespan(lifespan) {}

// Деструктор
Mammal::~Mammal() {}

// Сеттер для типу дихання
void Mammal::setBreathingType(const std::string& breathingType) {
    this->breathingType = breathingType;
}

// Сеттер для тривалості життя
void Mammal::setLifespan(int lifespan) {
    if (lifespan <= 0) {
        std::cerr << "Тривалість життя повинна бути позитивною!\n";
        return;
    }
    this->lifespan = lifespan;
}

// Геттер для типу дихання
std::string Mammal::getBreathingType() const {
    return breathingType;
}

// Геттер для тривалості життя
int Mammal::getLifespan() const {
    return lifespan;
}

// Виведення інформації про ссавця
void Mammal::display() const {
    MarineAnimal::display(); // Виклик методу базового класу
    std::cout << "Тип дихання: " << breathingType
              << ", Тривалість життя: " << lifespan << " років\n";
}
