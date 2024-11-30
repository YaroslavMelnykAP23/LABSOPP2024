#include "Fish_Lab11.h"
#include <iostream>
#include <limits> // Для std::numeric_limits

// Конструктор
Fish::Fish(std::string name, std::string habitat, double length,
           std::string finType, std::string fishType)
    : MarineAnimal(name, habitat, length), finType(finType), fishType(fishType) {}

// Деструктор
Fish::~Fish() {}

// Сеттер для типу плавців
void Fish::setFinType(const std::string& finType) {
    this->finType = finType;
}

// Сеттер для типу риби
void Fish::setFishType(const std::string& fishType) {
    this->fishType = fishType;
}

// Геттер для типу плавців
std::string Fish::getFinType() const {
    return finType;
}

// Геттер для типу риби
std::string Fish::getFishType() const {
    return fishType;
}

// Виведення інформації про рибу
void Fish::display() const {
    MarineAnimal::display();
    std::cout << "Тип плавців: " << finType
              << ", Тип риби: " << fishType << "\n";
}

void Fish::inputData() {
    // Введення для імені риби
    while (true) {
        std::cout << "Введіть ім'я риби (Shark): ";
        std::getline(std::cin, name);
        if (name == "Shark") {
            break;
        } else {
            std::cout << "Ім'я повинно бути 'Shark'. Спробуйте ще раз.\n";
        }
    }

    // Введення для середовища
    while (true) {
        std::cout << "Введіть середовище проживання (Sea): ";
        std::getline(std::cin, habitat);
        if (habitat == "Sea") {
            break;
        } else {
            std::cout << "Середовище повинно бути 'Sea'. Спробуйте ще раз.\n";
        }
    }

    // Вибір типу плавців
    std::cout << "Виберіть тип плавців:\n1. Гострі\n2. Круглі\n3. Прямі\n";
    int finChoice = 0;
    while (true) {
        std::cout << "Ваш вибір (1-3): ";
        std::cin >> finChoice;
        if (finChoice == 1 || finChoice == 2 || finChoice == 3) {
            break;
        } else {
            std::cout << "Невірний вибір. Виберіть число від 1 до 3.\n";
        }
    }

    // Встановлюємо тип плавців в залежності від вибору
    if (finChoice == 1) {
        finType = "Гострі";
    } else if (finChoice == 2) {
        finType = "Круглі";
    } else {
        finType = "Прямі";
    }

    // Вибір типу риби
    std::cout << "Виберіть тип риби:\n1. Морська\n2. Прісноводна\n";
    int fishChoice = 0;
    while (true) {
        std::cout << "Ваш вибір (1-2): ";
        std::cin >> fishChoice;
        if (fishChoice == 1 || fishChoice == 2) {
            break;
        } else {
            std::cout << "Невірний вибір. Виберіть число від 1 до 2.\n";
        }
    }

    // Встановлюємо тип риби в залежності від вибору
    if (fishChoice == 1) {
        fishType = "Морська";
    } else {
        fishType = "Прісноводна";
    }

    std::cin.ignore();  // Ігноруємо залишки введення після чисел

    // Введення довжини з перевіркою на діапазон
    std::cout << "Введіть довжину риби (від 5 до 9 метрів): ";
    while (true) {
        std::cin >> length;
        if (length >= 5.0 && length <= 9.0) {
            break;
        } else {
            std::cout << "Некоректна довжина. Введіть значення від 5 до 9: ";
        }
    }

    // Очистка вводу
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}