#pragma once
#include <iostream>
#include <limits>
#include <string>

// Пространство имен для безопасного ввода чисел
namespace SafeNumberInput {

    //const int maxBufferSize = std::numeric_limits<std::streamsize>::max();
    /*
        std::numeric_limits<std::streamsize>::max() возвращает максимальное значение, 
        которое может быть представлено типом std::streamsize.
        Таким образом мы игнорируем ВЕСЬ ВОЗМОЖНЫЙ ввод пользователя.
    */

    // Ввод целого числа с обработкой ошибок
    inline int Int(const std::string& prompt = "") {
        int num;
        std::cout << prompt;
        // Цикл продолжается, пока ввод не является целым числом
        while (!(std::cin >> num)) {
            std::cin.clear(); // Очищаем флаги ошибок в потоке ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем весь ввод до символа новой строки
            std::cout << "Неверный ввод. \n" << prompt;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем символ новой строки после успешного ввода
        return num;
    }

    // Ввод положительного целого числа с обработкой ошибок
    inline int positiveInt(const std::string& prompt = "") {
        int num = Int(prompt);
        // Цикл продолжается, пока ввод не является положительным целым числом
        while (num <= 0) {
            std::cout << "Неверный ввод. Пожалуйста, введите положительное целое число. \n";
            num = Int(prompt);
        }
        return num;
    }

    inline int zeroOrOne(const std::string& prompt = "") {
        int num = Int(prompt);
        // Цикл продолжается, пока ввод не является ни 1 ни 0
        while (num != 0 && num != 1) {
            std::cout << "Неверный ввод. Пожалуйста, введите 1 или 0. \n";
            num = Int(prompt);
        }
        return num;
    }

    // Ввод числа с плавающей точкой с обработкой ошибок
    inline double Double(const std::string& prompt = "") {
        double num;
        std::cout << prompt;
        // Цикл продолжается, пока ввод не является числом с плавающей точкой
        while (!(std::cin >> num)) {
            std::cin.clear(); // Очищаем флаги ошибок в потоке ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем весь ввод до символа новой строки
            std::cout << "Неверный ввод. \n" << prompt;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем символ новой строки после успешного ввода
        return num;
    }

    // Ввод положительного числа с плавающей точкой с обработкой ошибок
    inline double positiveDouble(const std::string& prompt = "") {
        double num = Double(prompt);
        // Цикл продолжается, пока ввод не является положительным числом с плавающей точкой
        while (num <= 0) {
            std::cout << "Неверный ввод. Пожалуйста, введите положительное число с плавающей точкой. \n";
            num = Double(prompt);
        }
        return num;
    }

}
