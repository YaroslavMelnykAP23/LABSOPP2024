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

    // Ввід даних з клавіатури
    int num;
    string date;
    double amount;

    cout << "\nВведіть дані для квитанції 3:" << endl;
    cout << "Номер: ";
    cin >> num;
    cout << "Дата (YYYY-MM-DD): ";
    cin >> date;
    cout << "Сума до сплати: ";
    cin >> amount;

    kvitancya kvitancya3(num, date, amount);

    cout << "\nКвитанція 3:" << endl;
    kvitancya3.display();

    return 0;
}
