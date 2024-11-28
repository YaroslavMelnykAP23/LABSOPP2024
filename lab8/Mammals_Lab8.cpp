#include "Mammals_Lab8.h"

Mammal::Mammal(std::string name, std::string habitat, double length,
               std::string breathingType, int lifespan)
    : MarineAnimal(name, habitat, length), breathingType(breathingType), lifespan(lifespan) {}

Mammal::~Mammal() {}

void Mammal::setBreathingType(const std::string& breathingType) {
    this->breathingType = breathingType;
}

void Mammal::setLifespan(int lifespan) {
    if (lifespan <= 0) {
        std::cerr << "Тривалість життя повинна бути позитивною!\n";
        return;
    }
    this->lifespan = lifespan;
}

std::string Mammal::getBreathingType() const {
    return breathingType;
}

int Mammal::getLifespan() const {
    return lifespan;
}

void Mammal::display() const {
    MarineAnimal::display();
    std::cout << "Тип дихання: " << breathingType
              << ", Тривалість життя: " << lifespan << " років\n";
}
