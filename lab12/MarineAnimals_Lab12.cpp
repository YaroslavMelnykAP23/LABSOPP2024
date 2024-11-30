#include "MarineAnimals_Lab12.h"
#include "exceptions.h"

MarineAnimals::MarineAnimals(const std::string& name, double weight, double length)
    : name(name), weight(weight), length(length) {}

bool MarineAnimals::isLatin(const std::string& input) {
    std::regex latinRegex("^[A-Za-z\\s]+$");
    if (!std::regex_match(input, latinRegex)) {
        throw InputValidationException("Помилка: використовуйте лише латинські символи!");
    }
    return true;
}

std::string MarineAnimals::inputLatinString(const std::string& prompt) {
    std::string result;
    while (true) {
        try {
            std::cout << prompt;
            std::getline(std::cin, result);
            if (isLatin(result)) {
                return result;
            }
        } catch (const InputValidationException& e) {
            std::cout << e.what() << "\n";
        }
    }
}

double MarineAnimals::inputDoubleInRange(const std::string& prompt, double min, double max) {
    double value;
    while (true) {
        try {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.fail() || value < min || value > max) {
                throw InputValidationException("Помилка: значення має бути в діапазоні від " + 
                                                std::to_string(min) + " до " + std::to_string(max) + "!");
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } catch (const InputValidationException& e) {
            std::cout << e.what() << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
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
