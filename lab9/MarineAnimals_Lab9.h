#ifndef MARINE_ANIMALS_H
#define MARINE_ANIMALS_H

#include <string>
#include <iostream>

class MarineAnimal {
protected:
    std::string name;
    std::string habitat;
    double length;
    int age;

public:
    MarineAnimal(std::string name, std::string habitat, double length, int age);
    virtual ~MarineAnimal();

    virtual void display() const;

    friend class FriendClass; // Дружній клас
};

#endif // MARINE_ANIMALS_H
