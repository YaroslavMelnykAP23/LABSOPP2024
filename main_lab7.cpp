#include "receipt_lab7.h"

int main() {
    Receipt receiptManager;

    while (true) {
        std::cout << "\n1. Додати квитанцію\n"
                  << "2. Вивести всі квитанції\n"
                  << "3. Вставити квитанцію\n"
                  << "4. Видалити квитанцію\n"
                  << "5. Очистити всі квитанції\n"
                  << "6. Обміняти квитанції\n"
                  << "7. Редагувати квитанцію\n"
                  << "8. Вийти\n"
                  << "Ваш вибір: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                receiptManager.addReceipt();
                break;
            case 2:
                receiptManager.printReceipts();
                break;
            case 3: {
                std::cout << "Введіть позицію для вставки: ";
                int index;
                std::cin >> index;
                receiptManager.insertReceipt(index);
                break;
            }
            case 4: {
                std::cout << "Введіть номер квитанції для видалення: ";
                int id;
                std::cin >> id;
                receiptManager.removeReceipt(id);
                break;
            }
            case 5:
                receiptManager.clearReceipts();
                break;
            case 6: {
                std::cout << "Введіть номери квитанцій для обміну: ";
                int id1, id2;
                std::cin >> id1 >> id2;
                receiptManager.swapReceipts(id1, id2);
                break;
            }
            case 7: {
                std::cout << "Введіть номер квитанції для редагування: ";
                int id;
                std::cin >> id;
                receiptManager.modifyReceipt(id);
                break;
            }
            case 8:
                std::cout << "Програма завершена." << std::endl;
                return 0;
            default:
                std::cerr << "Некоректний вибір!" << std::endl;
                break;
        }
    }
}
