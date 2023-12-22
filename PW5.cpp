#pragma once
#include <iostream>
#include <fstream>
#include "SafeNumberInput.cpp"
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;

// Функция нахождения НОД с помощью деления
inline int gcd_division(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция нахождения НОД с помощью вычитания
inline int gcd_subtraction(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

inline void euclid() {
    double a = SafeNumberInput::Int("Введите значение a: ");
    double b = SafeNumberInput::Int("Введите значение b: ");

    int gcd_div = gcd_division(a, b);
    int gcd_sub = gcd_subtraction(a, b);

    cout << "Наибольший общий делитель (" << a << " и " << b << ") с помощью деления: " << gcd_div << endl;
    cout << "Наибольший общий делитель (" << a << " и " << b << ") с помощью вычитания: " << gcd_sub << endl;
}

inline bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

inline void sieveOfEratosthenes() {
    int limit = SafeNumberInput::Int("Введите лимит: ");
     for (int i = 2; i <= limit; ++i) {
        if (is_prime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

inline void swapCipher() {
    string input_file_path, output_file_path;

    cout << "Введите путь к входному файлу: ";
    cin >> input_file_path;

    cout << "Введите путь к выходному файлу: ";
    cin >> output_file_path;

    ifstream input_file(input_file_path, ios::binary);
    ofstream output_file(output_file_path, ios::binary);

    if (!input_file.is_open() || !output_file.is_open()) {
        cerr << "Ошибка открытия файлов." << endl;
        return;
    }

    char symbol;
    while (input_file.get(symbol)) {
        symbol = static_cast<char>((symbol * 3) % 256);
        output_file.put(symbol);
    }

    input_file.close();
    output_file.close();

    cout << "Шифрование выполнено." << endl;
}

inline void shiftCipher() {
    string input_file_path, output_file_path;

    cout << "Введите путь к входному файлу: ";
    cin >> input_file_path;

    cout << "Введите путь к выходному файлу: ";
    cin >> output_file_path;

    ifstream input_file(input_file_path, ios::binary);
    ofstream output_file(output_file_path, ios::binary);

    if (!input_file.is_open() || !output_file.is_open()) {
        cerr << "Ошибка открытия файлов." << endl;
        return;
    }

    char symbol;
    while (input_file.get(symbol)) {
        symbol = static_cast<char>((symbol + 1) % 256);
        output_file.put(symbol);
    }

    input_file.close();
    output_file.close();

    cout << "Шифрование выполнено." << endl;
}

inline void sumOfDigits() {
    int n = SafeNumberInput::Int("Введите число: ");
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    cout << "Сумма цифр числа: " << sum << endl;
}

inline void averageHeight() {
    std::vector<int> heights;
    double sum = 0;
    double average;

    std::cout << "**** Анализ роста учеников ***\n";
    std::cout << "Введите рост (см) и нажмите <Enter>.\n";
    std::cout << "Для завершения введите 0 и нажмите <Enter>\n";

    while (true) {
        int height;
        std::cout << "-> ";
        std::cin >> height;

        if (height == 0) {
            break;
        }

        heights.push_back(height);
        sum += height;
    }

    average = sum / heights.size();
    std::cout << "Средний рост: " << average << " см\n";

    int aboveAverageCount = 0;
    for (int height : heights) {
        if (height > average) {
            aboveAverageCount++;
        }
    }

    std::cout << "У " << aboveAverageCount << " человек рост превышает средний.\n";

}

inline void createphonebook(const string& filename) {
    string name, phoneNumber;

    ofstream file(filename, ios::app);
    while (true) {
        cout << "Введите фамилию или введите 'end' для завершения ввода: ";
        cin >> name;
        if (name == "end") {
            break;
        }

        cout << "Введите номер телефона: ";
        cin >> phoneNumber;

        file << name << ": " << phoneNumber << endl;
    }
    file.close();

    cout << "Создан файл " << filename << " с информацией о ваших товарищах.\n";
}

inline void searchphonebook(const string& filename) {
    ifstream file(filename);
    bool found = false;

    string surname;
    cout << "Введите фамилию для поиска номеров телефонов: ";
    cin >> surname;

    string line;
    cout << "Номера телефонов с фамилией " << surname << ":\n";
    while (getline(file, line)) {
        if (line.find(surname) != string::npos) {
            found = true;
            cout << line << endl;
        }
    }

    if (!found) {
        cout << "Фамилия " << surname << " не найдена.\n";
    }

    file.close();
}

inline void phonebook() {
    string filename = "phone.txt";
    createphonebook(filename);
    searchphonebook(filename);
}

