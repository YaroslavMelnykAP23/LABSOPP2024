#ifndef MAMMALS_H_LAB8
#define MAMMALS_H_LAB8

#include "MarineAnimals_Lab8.h"

class Mammal : public MarineAnimal {
private:
    std::string breathingType; 
    int lifespan;              

public:
    Mammal(std::string name, std::string habitat, double length,
           std::string breathingType, int lifespan);
    ~Mammal();

    void setBreathingType(const std::string& breathingType);
    void setLifespan(int lifespan);

    std::string getBreathingType() const;
    int getLifespan() const;

    void display() const override;
};

#endif // MAMMALS_H_LAB8
