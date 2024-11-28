#include "Fish_Lab11.h"

// Конструктор з ініціалізацією базового класу
Fish::Fish(std::string name, std::string habitat, double length,
           std::string finType, std::string fishType)
    : MarineAnimal(name, habitat, length), finType(finType), fishType(fishType) {}

// Деструктор
Fish::~Fish() {}

// Сеттер для типу плавців
void Fish::setFinType(const std::string& finType) {
    this->finType = finType;
}

// Сеттер для типу риби
void Fish::setFishType(const std::string& fishType) {
    this->fishType = fishType;
}

// Геттер для типу плавців
std::string Fish::getFinType() const {
    return finType;
}

// Геттер для типу риби
std::string Fish::getFishType() const {
    return fishType;
}

// Виведення інформації про рибу
void Fish::display() const {
    MarineAnimal::display(); // Виклик методу базового класу
    std::cout << "Тип плавців: " << finType
              << ", Тип риби: " << fishType << "\n";
}
