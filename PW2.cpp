#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "SafeNumberInput.cpp"

using namespace std;


inline void calculateConus() {
    // Ввод размеров конуса с клавиатуры
    double R = SafeNumberInput::positiveDouble("Введите радиус большего основания R: ");
    double r = SafeNumberInput::positiveDouble("Введите радиус меньшего основания r: ");
    double h = SafeNumberInput::positiveDouble("Введите высоту h: ");

    if (R > r /* h уже > 0 */) {
        // Вычисление объема и полной поверхности усеченного конуса
        double volume = (1.0 / 3.0) * M_PI * h * (R * R + R * r + r * r);
        double l = sqrt((R - r) * (R - r) + h * h); // Вычисляем образующую конуса
        double surfaceArea = M_PI * (R * R + (R + r) * l + r * r);

        // Вывод результатов
        cout << "Объем усеченного конуса: " << volume << endl;
        cout << "Полная поверхность усеченного конуса: " << surfaceArea << endl;
    }
    else {
        cout << "Такого конуса не существует" << endl;
    }
   
}

inline void branch() {
    double x = SafeNumberInput::Double("Введите значение x: ");
    double a = SafeNumberInput::Double("Введите значение a: ");

    // Вычисление результата в зависимости от условий
    double result;
    if (abs(x) < 1) {
        // Если |x| < 1, то a * ln(|x|)
        result = a * log(abs(x));
    }
    else {
        // Если |x| >= 1, то квадратный корень(a - x^2)
        if ((a - x * x) >= 0) {
            result = sqrt(a - x * x);
        }  else {
            cout << "Корень из отрицательного числа сам посчитай :)" << endl;
            return;
        }
    }

    // Вывод результата
    cout << "Результат: " << result << endl;
}

inline void function() {
    // Ввод x, y и b с использованием SafeNumberInput
    double x = SafeNumberInput::Double("Введите значение x: ");
    double y = SafeNumberInput::Double("Введите значение y: ");
    double b = SafeNumberInput::Double("Введите значение b: ");

    // Вычисление функции z = ln(b-y)*sqrt(b-x)
    if (((b - y) > 0) && ((b - x) >= 0)) {
        double result = log(b - y) * sqrt(b - x);

        // Вывод результата
        cout << "Результат функции: " << result << endl;
    }
    else {
        cout << "ln от числа <= 0 не существует, так же как и корня" << endl;
    }
   
}

inline void order() {
    int n = SafeNumberInput::Int("Введите значение n: ");

    for (int i = n; i <= n + 10; i++) {
        cout << i;
        cout << "\n";
    }
}


inline void tabulation() {
    double y;
    for (double x = -4; x <= 4; x += 0.5) {
        cout << "x = " << x;
        if (x - 1 != 0) {
            y = (x * x - 2 * x + 2) / (x - 1);
            cout << ", y = " << y;
        }
        cout << "\n";
    }
}