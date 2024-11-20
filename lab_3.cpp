#include <iostream>
#include <cmath>

using namespace std;

double calcFunc(double x, double a, double b) {
    return sqrt(abs(b * x)) / atan(b * b / (a * a + x * x));
}

int main() {
    // Вхідні дані
    double x_start = -10;
    double x_end = -1;
    double h = 1;
    double a = 2.8;
    double b = 1.5;

    // Змінні для обчислення середнього арифметичного
    double sum = 0.0;
    int count = 0;

    // Табулювання функції
    cout << "x\t\ty\n";
    for (double x = x_start; x <= x_end; x += h) {
        double y = calcFunc(x, a, b);
        cout << x << "\t\t" << y << endl;

        // Перевірка умови y > 0.5
        if (y > 0.5) {
            sum += y;
            count++;
        }
    }

    // Обчислення середнього арифметичного
    if (count > 0) {
        double average = sum / count;
        cout << "Середнє арифметичне для y > 0.5: " << average << endl;
    } else {
        cout << "Немає значень y, що задовольняють умову y > 0.5." << endl;
    }

    return 0;
}