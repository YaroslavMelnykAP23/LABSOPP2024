#ifndef FISH_H
#define FISH_H

#include "MarineAnimals_Lab9.h"

class Fish : public MarineAnimal {
private:
    std::string finType;
    std::string fishType;

public:
    Fish(std::string name, std::string habitat, double length, int age, std::string finType, std::string fishType);
    ~Fish();

    void display() const override;
    
    void inputData();

    friend class FriendClass; // Дружній клас
};

#endif // FISH_H
