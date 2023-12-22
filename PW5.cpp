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

// ������� ���������� ��� � ������� �������
inline int gcd_division(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// ������� ���������� ��� � ������� ���������
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
    double a = SafeNumberInput::Int("������� �������� a: ");
    double b = SafeNumberInput::Int("������� �������� b: ");

    int gcd_div = gcd_division(a, b);
    int gcd_sub = gcd_subtraction(a, b);

    cout << "���������� ����� �������� (" << a << " � " << b << ") � ������� �������: " << gcd_div << endl;
    cout << "���������� ����� �������� (" << a << " � " << b << ") � ������� ���������: " << gcd_sub << endl;
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
    int limit = SafeNumberInput::Int("������� �����: ");
     for (int i = 2; i <= limit; ++i) {
        if (is_prime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

inline void swapCipher() {
    string input_file_path, output_file_path;

    cout << "������� ���� � �������� �����: ";
    cin >> input_file_path;

    cout << "������� ���� � ��������� �����: ";
    cin >> output_file_path;

    ifstream input_file(input_file_path, ios::binary);
    ofstream output_file(output_file_path, ios::binary);

    if (!input_file.is_open() || !output_file.is_open()) {
        cerr << "������ �������� ������." << endl;
        return;
    }

    char symbol;
    while (input_file.get(symbol)) {
        symbol = static_cast<char>((symbol * 3) % 256);
        output_file.put(symbol);
    }

    input_file.close();
    output_file.close();

    cout << "���������� ���������." << endl;
}

inline void shiftCipher() {
    string input_file_path, output_file_path;

    cout << "������� ���� � �������� �����: ";
    cin >> input_file_path;

    cout << "������� ���� � ��������� �����: ";
    cin >> output_file_path;

    ifstream input_file(input_file_path, ios::binary);
    ofstream output_file(output_file_path, ios::binary);

    if (!input_file.is_open() || !output_file.is_open()) {
        cerr << "������ �������� ������." << endl;
        return;
    }

    char symbol;
    while (input_file.get(symbol)) {
        symbol = static_cast<char>((symbol + 1) % 256);
        output_file.put(symbol);
    }

    input_file.close();
    output_file.close();

    cout << "���������� ���������." << endl;
}

inline void sumOfDigits() {
    int n = SafeNumberInput::Int("������� �����: ");
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    cout << "����� ���� �����: " << sum << endl;
}

inline void averageHeight() {
    std::vector<int> heights;
    double sum = 0;
    double average;

    std::cout << "**** ������ ����� �������� ***\n";
    std::cout << "������� ���� (��) � ������� <Enter>.\n";
    std::cout << "��� ���������� ������� 0 � ������� <Enter>\n";

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
    std::cout << "������� ����: " << average << " ��\n";

    int aboveAverageCount = 0;
    for (int height : heights) {
        if (height > average) {
            aboveAverageCount++;
        }
    }

    std::cout << "� " << aboveAverageCount << " ������� ���� ��������� �������.\n";

}

inline void createphonebook(const string& filename) {
    string name, phoneNumber;

    ofstream file(filename, ios::app);
    while (true) {
        cout << "������� ������� ��� ������� 'end' ��� ���������� �����: ";
        cin >> name;
        if (name == "end") {
            break;
        }

        cout << "������� ����� ��������: ";
        cin >> phoneNumber;

        file << name << ": " << phoneNumber << endl;
    }
    file.close();

    cout << "������ ���� " << filename << " � ����������� � ����� ���������.\n";
}

inline void searchphonebook(const string& filename) {
    ifstream file(filename);
    bool found = false;

    string surname;
    cout << "������� ������� ��� ������ ������� ���������: ";
    cin >> surname;

    string line;
    cout << "������ ��������� � �������� " << surname << ":\n";
    while (getline(file, line)) {
        if (line.find(surname) != string::npos) {
            found = true;
            cout << line << endl;
        }
    }

    if (!found) {
        cout << "������� " << surname << " �� �������.\n";
    }

    file.close();
}

inline void phonebook() {
    string filename = "phone.txt";
    createphonebook(filename);
    searchphonebook(filename);
}

