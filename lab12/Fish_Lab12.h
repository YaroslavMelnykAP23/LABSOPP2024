#ifndef FISH_H
#define FISH_H

#include "MarineAnimals_Lab12.h"

class Fish : public MarineAnimals {
private:
    int finsCount;
    bool isPredator;

public:
    Fish(const std::string& name = "", double weight = 0.0, double length = 0.0, int finsCount = 0, bool isPredator = false);

    void display() const override;
    void saveToFile(std::ofstream& outFile) const override;
    void loadFromFile(std::ifstream& inFile) override;
    void inputFromConsole() override;
    std::string toString() const override;
};

#endif // FISH_H
