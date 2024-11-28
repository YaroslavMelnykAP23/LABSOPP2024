#include "Fish_Lab8.h"

Fish::Fish(std::string name, std::string habitat, double length,
           std::string finType, std::string fishType)
    : MarineAnimal(name, habitat, length), finType(finType), fishType(fishType) {}

Fish::~Fish() {}

void Fish::setFinType(const std::string& finType) {
    this->finType = finType;
}

void Fish::setFishType(const std::string& fishType) {
    this->fishType = fishType;
}

std::string Fish::getFinType() const {
    return finType;
}

std::string Fish::getFishType() const {
    return fishType;
}

void Fish::display() const {
    MarineAnimal::display();
    std::cout << "Тип плавців: " << finType
              << ", Тип риби: " << fishType << "\n";
}
