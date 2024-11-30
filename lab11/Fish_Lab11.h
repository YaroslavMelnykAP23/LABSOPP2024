#ifndef FISH_H_LAB11
#define FISH_H_LAB11


#include "MarineAnimals_Lab11.h"
#include <string>

// Клас Fish, що наслідує MarineAnimal
class Fish : public MarineAnimal {
private:
    std::string finType;   // Тип плавців
    std::string fishType;  // Морська або прісноводна

public:
    // Конструктор
    Fish(std::string name, std::string habitat, double length,
         std::string finType, std::string fishType);
    
    // Деструктор
    ~Fish();

    // Сеттери
    void setFinType(const std::string& finType);
    void setFishType(const std::string& fishType);

    // Геттери
    std::string getFinType() const;
    std::string getFishType() const;

    // Віртуальний метод для відображення
    void display() const override;

    // Метод введення даних
    void inputData();
};

#endif // FISH_H_LAB8
