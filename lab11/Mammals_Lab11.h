#ifndef MAMMALS_H_LAB11
#define MAMMALS_H_LAB11

#include "MarineAnimals_Lab11.h" // Базовий клас

// Клас Mammal, що наслідує MarineAnimal
class Mammal : public MarineAnimal {
private:
    std::string breathingType; // Тип дихання
    int lifespan;              // Тривалість життя (у роках)

public:
    // Конструктор
    Mammal(std::string name, std::string habitat, double length,
           std::string breathingType, int lifespan);
    
    // Деструктор
    ~Mammal();

    // Сеттери
    void setBreathingType(const std::string& breathingType);
    void setLifespan(int lifespan);

    // Геттери
    std::string getBreathingType() const;
    int getLifespan() const;

    // Перевизначення методу display()
    void display() const override;
};

#endif // MAMMALS_H_LAB11
