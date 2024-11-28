#include "Fish_Lab9.h"

Fish::Fish(std::string name, std::string habitat, double length, int age, std::string finType, std::string fishType)
    : MarineAnimal(name, habitat, length, age), finType(finType), fishType(fishType) {}

Fish::~Fish() {}

void Fish::display() const {
    MarineAnimal::display();
    std::cout << "Тип плавців: " << finType << ", Тип риби: " << fishType << "\n";
}
