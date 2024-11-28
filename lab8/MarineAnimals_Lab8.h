#ifndef MARINE_ANIMALS_H_LAB8
#define MARINE_ANIMALS_H_LAB8

#include <string>
#include <iostream>

class MarineAnimal {
private:
    std::string name;
    std::string habitat; // середовище
    double length;       // довжина

public:
    MarineAnimal(std::string name, std::string habitat, double length);
    virtual ~MarineAnimal();

    void setName(const std::string& name);
    void setHabitat(const std::string& habitat);
    void setLength(double length);

    std::string getName() const;
    std::string getHabitat() const;
    double getLength() const;

    virtual void display() const; // Віртуальний метод для виведення
};

#endif // MARINE_ANIMALS_H_LAB8
