#ifndef MARINE_ANIMALS_H_LAB11
#define MARINE_ANIMALS_H_LAB11

#include <string>
#include <iostream>

// Базовий клас MarineAnimal
class MarineAnimal {
private:
    std::string name;     // Назва тварини
    std::string habitat;  // Середовище існування
    double length;        // Довжина (в метрах)

public:
    // Конструктор
    MarineAnimal(std::string name, std::string habitat, double length);
    
    // Віртуальний деструктор
    virtual ~MarineAnimal();

    // Сеттери
    void setName(const std::string& name);
    void setHabitat(const std::string& habitat);
    void setLength(double length);

    // Геттери
    std::string getName() const;
    std::string getHabitat() const;
    double getLength() const;

    // Віртуальний метод для виведення інформації
    virtual void display() const;
};

#endif // MARINE_ANIMALS_H_LAB11
