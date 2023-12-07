#pragma once
#include <iostream>
#include <fstream>
#include "SafeNumberInput.cpp"
#include <iomanip> // Для использования setprecision
#include <algorithm> // Для sort

using namespace std;


inline void calculateLoanPayment() {
    // Ввод данных о займе с клавиатуры
    double S = SafeNumberInput::positiveDouble("Введите сумму займа (S): ");
    double p = SafeNumberInput::positiveDouble("Введите годовую процентную ставку (в процентах): ");
    double n = SafeNumberInput::positiveDouble("Введите срок займа в годах (n): ");

    // Преобразование годовой процентной ставки в месячную
    double r = p / 100;

    // Вычисление ежемесячного платежа
    double m = (S * r * pow(1 + r, n)) / (12 *(pow(1 + r, n) - 1));

    // Вывод результата с фиксированной точностью
    cout << fixed << setprecision(2) << "Ежемесячный платеж по займу: " << m << endl;
}

inline void calculateLoanRate() {
    // Ввод данных о ссуде с клавиатуры
    double S = SafeNumberInput::positiveDouble("Введите сумму ссуды (S): ");
    double m = SafeNumberInput::positiveDouble("Введите ежемесячный платеж (m): ");
    double n = SafeNumberInput::positiveDouble("Введите срок ссуды в годах (n): ");

    // Вычисление годовой процентной ставки
    double S_ = m * 12 * n;
    double p = (S_ - S) / S * 100;

    // Вывод результата с фиксированной точностью
    cout << "Процентная ставка по ссуде: " << fixed << setprecision(2) << p << "%" << endl;
}


inline void file() {
    ofstream outFile("example.txt");

    if (outFile.is_open()) {
        outFile << "1 Пример текста в файле." << endl;
        outFile << "2 Вторая строка текста." << endl;
        outFile << "3 Еще одна строка." << endl;

        outFile.close();
    } else {
        cerr << "Не удалось открыть файл для записи." << endl;
    }

    // Копирование содержимого файла на экран
    ifstream inFile("example.txt");

    if (inFile.is_open()) {
        char ch;
        while (inFile.get(ch)) {
            cout << ch;
        }

        inFile.close();
    }else {
        cerr << "Не удалось открыть файл для чтения." << endl;
    }
}

inline void filter() {
    string filename = "example.txt";
    // Открытие файла для чтения
    ifstream inFile(filename);

    if (inFile.is_open()) {
        char ch;
        while (inFile.get(ch)) {
            // Проверяем, является ли символ цифрой
            if (isdigit(ch)) {
                cout << ch;
            }
        }

        inFile.close();
    }else {
        cerr << "Не удалось открыть файл для чтения." << endl;
    }
}

inline void sort() {
    string str = "JVNKJHADHJKJKLKUMOBASKMDOPQASMKDLODPIDASMVH";
    // Используем функцию sort для сортировки букв в строке
    sort(str.begin(), str.end());

    // Выводим отсортированную строку
    cout << "Отсортированная строка: " << str << endl;
}

