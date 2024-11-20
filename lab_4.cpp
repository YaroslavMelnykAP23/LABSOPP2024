#include <iostream>
#include <string>
using namespace std;

class kvitancya {
private:
    int number;
    string date;
    double amount;

public:
    // Конструктор
    kvitancya(int num, string d, double amt) : number(num), date(d), amount(amt) {}

    // Метод для встановлення значень
    void setValues(int num, string d, double amt) {
        number = num;
        date = d;
        amount = amt;
    }

    // Метод для виведення інформації
    void display() const {
        cout << "номер: " << number << endl;
        cout << "дата: " << date << endl;
        cout << "сума до сплати: " << amount << endl;
    }
};

int main() {
    // Пряме ініціалізування
    kvitancya kvitancya1(101, "2024-10-13", 150.75);
    
    // Використання методу для встановлення значень
    kvitancya kvitancya2(0, "", 0.0); // Ініціалізація з початковими значеннями
    kvitancya2.setValues(102, "2024-11-14", 200.50);

    // Виведення даних
    cout << "Квитанція 1:" << endl;
    kvitancya1.display();

    cout << "\nКвитанція 2:" << endl;
    kvitancya2.display();

    return 0;
}