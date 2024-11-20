#include <iostream>
#include <cmath> // 1. 
#include <iomanip> // додана щоб контролювати формат виведення чисел
// 2, 3.
struct Param { double a; double b; double x; double y; };

enum FunFla { CASE1, CASE2, CASE3 };

// 4. Функція для перевірки умови і повертання прапорця
FunFla checkCond(const Param &params) {
    double ax = params.a * params.x;
    if (ax < 1) {
        return CASE1;
    } else if (ax >= 1 && ax < 2) {
        return CASE2;
    } else {
        return CASE3;
    }
}
// 5.
// Сase 1: ln^3(|ax + b| + 1)
double calcCase1(const Param &params) {
    double ax_b = params.a * params.x + params.b;
    return pow(log(fabs(ax_b) + 1), 3);
}

// Case 2: e^(-sqrt(x^2 + a^2)) * sin(bx)
double calcCase2(const Param &params) {
    return exp(-sqrt(pow(params.x, 2) + pow(params.a, 2))) * sin(params.b * params.x);
}

// Case 3: arctan(ax - b)
double calcCase3(const Param &params) {
    return atan(params.a * params.x - params.b);
}

// 6.
// Головна функція для розрахунку y
double calcY(Param &params) {
    FunFla flag = checkCond(params);
    switch (flag) {
        case CASE1:
            return calcCase1(params);
        case CASE2:
            return calcCase2(params);
        case CASE3:
            return calcCase3(params);
        default:
            std::cerr << "Invalid condition" << std::endl;
            return 0;
    }
}
// 7.
int main() {
    Param params;

    // Input data
    std::cout << "Введіть значення для a: ";
    std::cin >> params.a;
    std::cout << "Введіть значення для b: ";
    std::cin >> params.b;
    std::cout << "Введіть значення для x: ";
    std::cin >> params.x;

    // Calculate y based on the input
    params.y = calcY(params);

    // Output the results
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "вхідні значення:" << std::endl;
    std::cout << "a = " << params.a << ", b = " << params.b << ", x = " << params.x << std::endl;
    std::cout << "результат y = " << params.y << std::endl;

    return 0;
}