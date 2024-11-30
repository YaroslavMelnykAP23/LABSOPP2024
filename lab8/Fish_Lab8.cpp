#include "Fish_Lab8.h"
#include <iostream>
#include <limits>

Fish::Fish(std::string name, std::string habitat, double length,
           std::string finType, std::string fishType)
    : MarineAnimal(name, habitat, length), finType(finType), fishType(fishType) {}

Fish::~Fish() {}

void Fish::setFinType(const std::string& finType) {
    this->finType = finType;
}

void Fish::setFishType(const std::string& fishType) {
    this->fishType = fishType;
}

std::string Fish::getFinType() const {
    return finType;
}

std::string Fish::getFishType() const {
    return fishType;
}

void Fish::display() const {
    MarineAnimal::display();
    std::cout << "Тип плавців: " << finType
              << ", Тип риби: " << fishType << "\n";
}

void Fish::inputData() {
    // Введення імені
    std::string inputName;
    while (true) {
        std::cout << "Введіть ім'я риби (Shark): ";
        std::getline(std::cin, inputName);
        if (inputName == "Shark") {
            setName(inputName);
            break;
        } else {
            std::cout << "Ім'я має бути 'Shark'. Спробуйте ще раз.\n";
        }
    }

    // Введення середовища
    std::string inputHabitat;
    while (true) {
        std::cout << "Введіть середовище проживання (Sea): ";
        std::getline(std::cin, inputHabitat);
        if (inputHabitat == "Sea") {
            setHabitat(inputHabitat);
            break;
        } else {
            std::cout << "Середовище проживання має бути 'Sea'. Спробуйте ще раз.\n";
        }
    }

    // Введення довжини
    double inputLength;
    while (true) {
        std::cout << "Введіть довжину риби (від 5 до 9 м): ";
        if (std::cin >> inputLength && inputLength >= 5.0 && inputLength <= 9.0) {
            setLength(inputLength);
            break;
        } else {
            std::cout << "Довжина має бути в межах від 5 до 9 м. Спробуйте ще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cin.ignore(); // Очищення буфера вводу

    // Тип плавців і тип риби встановлюються автоматично
    finType = "Гострі";
    fishType = "Морська";
}
