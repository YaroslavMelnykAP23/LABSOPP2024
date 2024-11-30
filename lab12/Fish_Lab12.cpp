#include "Fish_Lab12.h"
#include <sstream>

Fish::Fish(const std::string& name, double weight, double length, int finsCount, bool isPredator)
    : MarineAnimals(name, weight, length), finsCount(finsCount), isPredator(isPredator) {}

void Fish::display() const {
    MarineAnimals::display();
    std::cout << "Кількість плавників: " << finsCount << ", Хижак: " << (isPredator ? "Так" : "Ні") << "\n";
}

void Fish::saveToFile(std::ofstream& outFile) const {
    outFile << toString();
}

void Fish::loadFromFile(std::ifstream& inFile) {
    MarineAnimals::loadFromFile(inFile);
    inFile >> finsCount >> isPredator;
}

void Fish::inputFromConsole() {
    name = inputLatinString("Введіть назву риби (латиницею): ");
    weight = inputDoubleInRange("Введіть вагу риби (2-44 кг): ", 2.0, 44.0);
    length = inputDoubleInRange("Введіть довжину риби (0.1-20 м): ", 0.1, 20.0);
    finsCount = static_cast<int>(inputDoubleInRange("Введіть кількість плавників (2-15): ", 2, 15));
    std::cout << "Риба є хижаком? (1 - Так, 0 - Ні): ";
    std::cin >> isPredator;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string Fish::toString() const {
    std::ostringstream oss;
    oss << MarineAnimals::toString();
    oss << "Кількість плавників: " << finsCount << ", Хижак: " << (isPredator ? "Так" : "Ні") << "\n";
    return oss.str();
}