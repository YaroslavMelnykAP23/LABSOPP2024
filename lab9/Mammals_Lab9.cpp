#include "Mammals_Lab9.h"

Mammal::Mammal(std::string name, std::string habitat, double length, int age, std::string breathingType, int lifespan)
    : MarineAnimal(name, habitat, length, age), breathingType(breathingType), lifespan(lifespan) {}

Mammal::~Mammal() {}

void Mammal::display() const {
    MarineAnimal::display();
    std::cout << "Тип дихання: " << breathingType << ", Тривалість життя: " << lifespan << " років\n";
}
