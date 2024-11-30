#ifndef MAMMALS_H
#define MAMMALS_H

#include "MarineAnimals_Lab12.h"

class Whale : public MarineAnimals {
public:
    Whale(const std::string& name = "", double weight = 0.0, double length = 0.0);
    void display() const override;
    void saveToFile(std::ofstream& outFile) const override;
    void loadFromFile(std::ifstream& inFile) override;
    void inputFromConsole() override;
    std::string toString() const override;
};

class Dolphin : public MarineAnimals {
public:
    Dolphin(const std::string& name = "", double weight = 0.0, double length = 0.0);
    void display() const override;
    void saveToFile(std::ofstream& outFile) const override;
    void loadFromFile(std::ifstream& inFile) override;
    void inputFromConsole() override;
    std::string toString() const override;
};

#endif // MAMMALS_H
