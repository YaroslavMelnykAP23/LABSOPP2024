#include "MarineAnimals_Lab12.h"

MarineAnimals::MarineAnimals(const std::string& name, double weight, double length)
    : name(name), weight(weight), length(length) {}

bool MarineAnimals::isLatin(const std::string& input) {
    std::regex latinRegex("^[A-Za-z\\s]+$"); // Перевіряє, чи рядок складається лише з латиниці
    return std::regex_match(input, latinRegex);
}

std::string MarineAnimals::inputLatinString(const std::string& prompt) {
    std::string result;
    do {
        std::cout << prompt;
        std::getline(std::cin, result);
        if (!isLatin(result)) {
            std::cout << "Помилка: використовуйте лише латинські символи!\n";
        }
    } while (!isLatin(result));
    return result;
}

double MarineAnimals::inputDoubleInRange(const std::string& prompt, double min, double max) {
    double value;
    do {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < min || value > max) {
            std::cout << "Помилка: введіть значення в діапазоні від " << min << " до " << max << ".\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (value < min || value > max || std::cin.fail());
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка потоку
    return value;
}

void MarineAnimals::display() const {
    std::cout << "Назва: " << name << ", Вага: " << weight << " кг, Довжина: " << length << " м\n";
}

void MarineAnimals::saveToFile(std::ofstream& outFile) const {
    outFile << toString();
}

void MarineAnimals::loadFromFile(std::ifstream& inFile) {
    inFile >> name >> weight >> length;
}

std::string MarineAnimals::toString() const {
    std::ostringstream oss;
    oss << "Назва: " << name << ", Вага: " << weight << " кг, Довжина: " << length << " м\n";
    return oss.str();
}
