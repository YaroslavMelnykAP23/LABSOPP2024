#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Receipt {
private:
    int number;
    string date;
    double amount;

public:
    // Конструктор за замовчуванням
    Receipt() : number(0), date(""), amount(0.0) {}

    // Конструктор з параметрами
    Receipt(int num, string d, double amt) : number(num), date(d), amount(amt) {}

    // Деструктор
    ~Receipt() {
        cout << "Квитанція з номером " << number << " видалена.\n";
    }

    // Метод для встановлення значень з валідацією
    void setValues(int num, string d, double amt) {
        if (num > 0) {
            number = num;
        } else {
            cout << "Невірний номер квитанції.\n";
        }
        
        date = d;  // Можна додати валідацію дати, якщо потрібно
        
        if (amt >= 0) {
            amount = amt;
        } else {
            cout << "Сума не може бути від'ємною.\n";
        }
    }

    // Метод для виведення інформації
    void display() const {
        cout << "Номер квитанції: " << number << endl;
        cout << "Дата: " << date << endl;
        cout << "Сума: " << amount << endl;
    }

    // Гетери для критеріїв пошуку
    int getNumber() const { return number; }
    string getDate() const { return date; }
    double getAmount() const { return amount; }
};

// Функція для виведення квитанцій за певним критерієм
void displayReceiptsAboveAmount(const vector<Receipt>& receipts, double threshold) {
    bool found = false;
    for (const auto& receipt : receipts) {
        if (receipt.getAmount() > threshold) {
            receipt.display();
            found = true;
            cout << endl;
        }
    }
    if (!found) {
        cout << "Квитанції з сумою більше $" << threshold << " не знайдено.\n";
    }
}

int main() {
    // Створення екземплярів класу з використанням конструктора з параметрами
    Receipt receipt1(101, "2024-11-13", 150.75);
    Receipt receipt2(102, "2024-11-14", 200.50);
    
    // Використання конструктора за замовчуванням та методу setValues
    Receipt receipt3;
    receipt3.setValues(103, "2024-11-15", 300.25);

    // Виведення даних
    cout << "Деталі квитанції 1:" << endl;
    receipt1.display();

    cout << "\nДеталі квитанції 2:" << endl;
    receipt2.display();

    cout << "\nДеталі квитанції 3:" << endl;
    receipt3.display();

    // об'єкт з клавіатри
    Receipt receipt4;
    cout << "\nВведіть номер квитанції: ";
    int num;
    cin >> num;
    cout << "Введіть дату (у форматі YYYY-MM-DD): ";
    string date;
    cin >> date;
    cout << "Введіть суму до сплати: ";
    double amount;
    cin >> amount;
    receipt4.setValues(num, date, amount);

    // Виведення даних об'єкта
    cout << "\nДеталі квитанції 4:" << endl;
    receipt4.display();

    // Зберігання екземплярів у векторі
    vector<Receipt> receipts = {receipt1, receipt2, receipt3, receipt4};

    // Виведення квитанцій, де сума більше певного значення
    cout << "\nКвитанції з сумою більше 200:\n";
    displayReceiptsAboveAmount(receipts, 200);

    return 0;
}
