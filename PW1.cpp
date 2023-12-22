#pragma once
#include <iostream>
#include "SafeNumberInput.cpp"

using namespace std;

inline void name() {
    cout << "Артём";
}

inline void arithmetic() {
    // Ввод двух чисел с клавиатуры
    double num1, num2;
    num1 = SafeNumberInput::Double("Введите первое число: ");
    num2 = SafeNumberInput::Double("Введите второе число: ");

    // Вычисление и вывод результатов
    cout << "Сумма: " << num1 + num2 << endl;
    cout << "Разность: " << num1 - num2 << endl;
    cout << "Произведение: " << num1 * num2 << endl;

    // Проверка на ноль, чтобы избежать деления на ноль
    if (num2 != 0) {
        cout << "Частное: " << num1 / num2 << endl;
    }
    else {
        cout << "Невозможно вычислить частное, так как делитель равен нулю." << endl;
    }
}

inline void solveEquation() {
    // Ввод коэффициентов b и c с клавиатуры
    double b, c;
    b = SafeNumberInput::Double("Введите коэффициент b: ");
    c = SafeNumberInput::Double("Введите коэффициент c: ");

    // Проверка, является ли уравнение вырожденным (b = 0)
    if (b == 0) {
        if (c == 0) {
            cout << "Уравнение имеет бесконечное множество решений." << endl;
        } else {
            cout << "Уравнение не имеет решений." << endl;
        }
    } else {
        // Решение уравнения и вывод результата
        double x = -c / b;
        cout << "Решение уравнения " << b << "x + " << c << " = 0" << endl;
        cout << "x = " << x << endl;
    }
}

inline void solveQuadraticEquation() {
    // Ввод коэффициентов a, b и c с клавиатуры
    double a = SafeNumberInput::Double("Введите коэффициент a: ");
    double b = SafeNumberInput::Double("Введите коэффициент b: ");
    double c = SafeNumberInput::Double("Введите коэффициент c: ");

    // Вычисление дискриминанта
    double discriminant = b * b - 4 * a * c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Уравнение имеет бесконечное множество решений." << endl;
            }
            else {
                cout << "Уравнение не имеет решений." << endl;
            }
        }
        else {
            // Решение уравнения и вывод результата
            double x = -c / b;
            cout << "Решение уравнения " << b << "x + " << c << " = 0" << endl;
            cout << "x = " << x << endl;
        }
    }
    else {
        if (discriminant > 0) {
            // Два действительных корня
            double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
            double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
            cout << "Уравнение имеет два действительных корня: x1 = " << root1 << ", x2 = " << root2 << std::endl;
        }
        else if (discriminant == 0) {
            // Один действительный корень
            double root = -b / (2 * a);
            cout << "Уравнение имеет один действительный корень: x = " << root << std::endl;
        }
        else {
            // Два комплексных корня
            double realPart = -b / (2 * a);
            double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
            cout << "Уравнение имеет два комплексных корня: x1 = " << realPart << " + " << imaginaryPart << "i, x2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
        }
    }
}

inline void isRoomBright() {
    bool isDaytime = SafeNumberInput::zeroOrOne("На улице день? 1 - да, 0 - нет\n");
    bool areCurtainsOpen = SafeNumberInput::zeroOrOne("Шторы открыты? 1 - да, 0 - нет\n");
    bool isLampOn = SafeNumberInput::zeroOrOne("Лампа включена? 1 - да, 0 - нет\n");


    bool isRoomBright = (isDaytime && areCurtainsOpen) || isLampOn;

    cout << "В комнате сейчас " << (isRoomBright ? "светло" : "темно");
}