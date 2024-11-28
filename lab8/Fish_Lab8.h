#ifndef FISH_H_LAB8
#define FISH_H_LAB8

#include "MarineAnimals_Lab8.h"

class Fish : public MarineAnimal {
private:
    std::string finType;
    std::string fishType; // Морська або прісноводна

public:
    Fish(std::string name, std::string habitat, double length,
         std::string finType, std::string fishType);
    ~Fish();

    void setFinType(const std::string& finType);
    void setFishType(const std::string& fishType);

    std::string getFinType() const;
    std::string getFishType() const;

    void display() const override;
};

#endif // FISH_H_LAB8
