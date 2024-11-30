#ifndef MARINE_ANIMALS_H
#define MARINE_ANIMALS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <regex>

class MarineAnimals {
protected:
    std::string name;
    double weight;
    double length;

    // Перевірка, чи всі символи рядка є латиницею
    bool isLatin(const std::string& input);

    // Читання рядка з перевіркою латиниці
    std::string inputLatinString(const std::string& prompt);

    // Читання числа з перевіркою діапазону
    double inputDoubleInRange(const std::string& prompt, double min, double max);

public:
    MarineAnimals(const std::string& name = "", double weight = 0.0, double length = 0.0);
    virtual ~MarineAnimals() = default;

    virtual void display() const;
    virtual void saveToFile(std::ofstream& outFile) const;
    virtual void loadFromFile(std::ifstream& inFile);

    virtual void inputFromConsole() = 0;
    virtual std::string toString() const;
};

#endif // MARINE_ANIMALS_H
