#pragma once
#include <iostream>
#include <fstream>
#include "SafeNumberInput.cpp"
#include <iomanip> // ��� ������������� setprecision
#include <algorithm> // ��� sort

using namespace std;


inline void calculateLoanPayment() {
    // ���� ������ � ����� � ����������
    double S = SafeNumberInput::positiveDouble("������� ����� ����� (S): ");
    double p = SafeNumberInput::positiveDouble("������� ������� ���������� ������ (� ���������): ");
    double n = SafeNumberInput::positiveDouble("������� ���� ����� � ����� (n): ");

    // �������������� ������� ���������� ������ � ��������
    double r = p / 100;

    // ���������� ������������ �������
    double m = (S * r * pow(1 + r, n)) / (12 *(pow(1 + r, n) - 1));

    // ����� ���������� � ������������� ���������
    cout << fixed << setprecision(2) << "����������� ������ �� �����: " << m << endl;
}

inline void calculateLoanRate() {
    // ���� ������ � ����� � ����������
    double S = SafeNumberInput::positiveDouble("������� ����� ����� (S): ");
    double m = SafeNumberInput::positiveDouble("������� ����������� ������ (m): ");
    double n = SafeNumberInput::positiveDouble("������� ���� ����� � ����� (n): ");

    // ���������� ������� ���������� ������
    double S_ = m * 12 * n;
    double p = (S_ - S) / S * 100;

    // ����� ���������� � ������������� ���������
    cout << "���������� ������ �� �����: " << fixed << setprecision(2) << p << "%" << endl;
}


inline void file() {
    ofstream outFile("example.txt");

    if (outFile.is_open()) {
        outFile << "1 ������ ������ � �����." << endl;
        outFile << "2 ������ ������ ������." << endl;
        outFile << "3 ��� ���� ������." << endl;

        outFile.close();
    } else {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
    }

    // ����������� ����������� ����� �� �����
    ifstream inFile("example.txt");

    if (inFile.is_open()) {
        char ch;
        while (inFile.get(ch)) {
            cout << ch;
        }

        inFile.close();
    }else {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
    }
}

inline void filter() {
    string filename = "example.txt";
    // �������� ����� ��� ������
    ifstream inFile(filename);

    if (inFile.is_open()) {
        char ch;
        while (inFile.get(ch)) {
            // ���������, �������� �� ������ ������
            if (isdigit(ch)) {
                cout << ch;
            }
        }

        inFile.close();
    }else {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
    }
}

inline void sort() {
    string str = "JVNKJHADHJKJKLKUMOBASKMDOPQASMKDLODPIDASMVH";
    // ���������� ������� sort ��� ���������� ���� � ������
    sort(str.begin(), str.end());

    // ������� ��������������� ������
    cout << "��������������� ������: " << str << endl;
}

