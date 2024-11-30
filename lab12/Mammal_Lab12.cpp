#include "Mammal_Lab12.h"
#include <sstream>

// Реалізація класу Whale
Whale::Whale(const std::string& name, double weight, double length)
    : MarineAnimals(name, weight, length) {}

void Whale::display() const {
    std::cout << "Кит: ";
    MarineAnimals::display();
}

void Whale::saveToFile(std::ofstream& outFile) const {
    outFile << toString();
}

void Whale::loadFromFile(std::ifstream& inFile) {
    MarineAnimals::loadFromFile(inFile);
}

void Whale::inputFromConsole() {
    name = inputLatinString("Введіть назву кита (латиницею): ");
    weight = inputDoubleInRange("Введіть вагу кита (5000-150000 кг): ", 5000.0, 150000.0); // Вага в кг
    length = inputDoubleInRange("Введіть довжину кита (20-33 м): ", 20.0, 33.0);
}

std::string Whale::toString() const {
    std::ostringstream oss;
    oss << "Кит: " << MarineAnimals::toString();
    return oss.str();
}

// Реалізація класу Dolphin
Dolphin::Dolphin(const std::string& name, double weight, double length)
    : MarineAnimals(name, weight, length) {}

void Dolphin::display() const {
    std::cout << "Дельфін: ";
    MarineAnimals::display();
}

void Dolphin::saveToFile(std::ofstream& outFile) const {
    outFile << toString();
}

void Dolphin::loadFromFile(std::ifstream& inFile) {
    MarineAnimals::loadFromFile(inFile);
}

void Dolphin::inputFromConsole() {
    name = inputLatinString("Введіть назву дельфіна (латиницею): ");
    weight = inputDoubleInRange("Введіть вагу дельфіна (50-7200 кг): ", 50.0, 7200.0);
    length = inputDoubleInRange("Введіть довжину дельфіна (1-12 м): ", 1.0, 12.0);
}

std::string Dolphin::toString() const {
    std::ostringstream oss;
    oss << "Дельфін: " << MarineAnimals::toString();
    return oss.str();
}
