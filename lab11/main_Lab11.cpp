#include "Fish_Lab11.h"    
#include "Mammals_Lab11.h" 
#include <vector>
#include <iostream>
#include <memory> // Для std::unique_ptr
#include <limits> 

// Функція для додавання риби
void addFish(std::vector<MarineAnimal*>& animals) {
    auto fish = std::make_unique<Fish>("", "", 0.0, "", ""); // Тимчасовий об'єкт
    fish->inputData(); // Виклик методу введення
    animals.push_back(fish.release()); // Передаємо об'єкт у вектор
}

// Функція для статичного додавання ссавців
void addMammals(std::vector<MarineAnimal*>& animals) {
    animals.push_back(new Mammal("Дельфін", "Океан", 2.5, "Легені", 30));
    animals.push_back(new Mammal("Кит", "Океан", 15.0, "Легені", 70));
}

// Функція для перегляду списку морських тварин
void displayAnimals(const std::vector<MarineAnimal*>& animals) {
    if (animals.empty()) {
        std::cout << "Список морських тварин порожній.\n";
        return;
    }
    std::cout << "Список морських тварин:\n";
    for (const auto& animal : animals) {
        animal->display();
        std::cout << "----------------------\n";
    }
}

// Функція для видалення всіх об'єктів
void clearAnimals(std::vector<MarineAnimal*>& animals) {
    for (auto& animal : animals) {
        delete animal; // Видалення об'єкта
    }
    animals.clear(); // Очищення вектора
}

int main() {
    std::vector<MarineAnimal*> animals; // Вектор для морських тварин
    int choice = 0;

    
    addMammals(animals);

    do {
        // Виведення меню
        std::cout << "\nМеню:\n"
                  << "1. Додати рибу\n"
                  << "2. Переглянути список морських тварин\n"
                  << "3. Завершити програму\n"
                  << "Ваш вибір: ";
        std::cin >> choice;

        // Очистка залишків вводу
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addFish(animals); // Додавання риби
                break;
            case 2:
                displayAnimals(animals); // Виведення списку
                break;
            case 3:
                std::cout << "Завершення програми...\n";
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 3);

    // Очищення пам'яті перед завершенням програми
    clearAnimals(animals);

    return 0;
}