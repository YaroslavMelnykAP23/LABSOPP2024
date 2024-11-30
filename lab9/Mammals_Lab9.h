#ifndef MAMMAL_H
#define MAMMAL_H

#include "MarineAnimals_Lab9.h"

class Mammal : public MarineAnimal {
private:
    std::string breathingType;
    int lifespan;

public:
    Mammal(std::string name, std::string habitat, double length, int age, std::string breathingType, int lifespan);
    ~Mammal();

    void display() const override;

    friend class FriendClass; // Дружній клас
};

#endif // MAMMAL_H
