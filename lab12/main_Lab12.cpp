#include "Fish_Lab12.h"
#include "Mammal_Lab12.h"
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>

// Функція для виведення меню
void displayMenu() {
    std::cout << "\nСистема управління морськими тваринами (вводити відповіді тільки на латиниці)\n";
    std::cout << "1. Додати рибу\n";
    std::cout << "2. Додати кита\n";
    std::cout << "3. Додати дельфіна\n";
    std::cout << "4. Переглянути всіх тварин\n";
    std::cout << "5. Зберегти тварин у файл\n";
    std::cout << "6. Завантажити тварин з файлу\n";
    std::cout << "7. Вихід\n";
    std::cout << "Введіть свій вибір: ";
}

int main() {
    std::vector<std::shared_ptr<MarineAnimals>> marineAnimals;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера

        switch (choice) {
        case 1: {
            // Додати рибу
            auto fish = std::make_shared<Fish>();
            fish->inputFromConsole();
            marineAnimals.push_back(fish);
            std::cout << "Рибу додано успішно!\n";
            break;
        }
        case 2: {
            // Додати кита
            auto whale = std::make_shared<Whale>();
            whale->inputFromConsole();
            marineAnimals.push_back(whale);
            std::cout << "Кита додано успішно!\n";
            break;
        }
        case 3: {
            // Додати дельфіна
            auto dolphin = std::make_shared<Dolphin>();
            dolphin->inputFromConsole();
            marineAnimals.push_back(dolphin);
            std::cout << "Дельфіна додано успішно!\n";
            break;
        }
        case 4: {
            // Переглянути всіх тварин
            if (marineAnimals.empty()) {
                std::cout << "Немає даних для перегляду.\n";
            } else {
                for (size_t i = 0; i < marineAnimals.size(); ++i) {
                    std::cout << "Тварина #" << (i + 1) << ":\n";
                    marineAnimals[i]->display();
                    std::cout << "--------------------\n";
                }
            }
            break;
        }
        case 5: {
            // Зберегти у файл
            std::ofstream outFile("marine_animals.txt");
            if (!outFile) {
                std::cout << "Помилка: не вдалося відкрити файл для запису.\n";
                break;
            }
            for (size_t i = 0; i < marineAnimals.size(); ++i) {
                outFile << "Тварина #" << (i + 1) << ":\n";
                outFile << marineAnimals[i]->toString();
                outFile << "--------------------\n";
            }
            outFile.close();
            std::cout << "Тварин успішно збережено у файл!\n";
            break;
        }
        case 6: {
            // Завантажити з файлу
            std::ifstream inFile("marine_animals.txt");
            if (!inFile) {
                std::cout << "Помилка: не вдалося відкрити файл для читання.\n";
                break;
            }
            marineAnimals.clear();
            std::cout << "Завантаження з файлу не реалізоване (лише перегляд вмісту файлу):\n";
            std::string line;
            while (std::getline(inFile, line)) {
                std::cout << line << "\n";
            }
            inFile.close();
            break;
        }
        case 7:
            std::cout << "Вихід із програми. До побачення!\n";
            break;
        default:
            std::cout << "Помилка: невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 7);

    return 0;
}
