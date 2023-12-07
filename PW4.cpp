#pragma once
#include <iostream>
#include <fstream>
#include "SafeNumberInput.cpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <Windows.h>


using namespace std;

inline void numbersFile() {
    string filename = "example2.txt";
    // �������� ����� � ������ � ���� 10 �����
    ofstream outFile(filename);

    if (outFile.is_open()) {
        for (int i = 1; i <= 10; ++i) {
            outFile << i << endl;
        }

        outFile.close();
        cout << "����� ������� �������� � ����." << endl;
    }
    else {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
        return;
    }

    // �������� ����� ��� ������ � ���������� ����� �����
    ifstream inFile(filename);

    if (inFile.is_open()) {
        int number;
        int sum = 0;

        while (inFile >> number) {
            sum += number;
        }

        inFile.close();
        cout << "����� ����� �� �����: " << sum << endl;
    }
    else {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
    }
}

inline int signFunc(double value) {
    return (value > 0) - (value < 0);
    /*  ���� value > 0 ������ 1 - 0 = 1
        ���� value < 0 ������ 0 - 1 = -1
        � ������ ������ ����� 0 - 0 = 0
        ��� �������� ��� ������� ������     */
}

inline void sign() {
    double x = SafeNumberInput::Double("������� ��������: ");
    cout << signFunc(x);
}

inline void area() {
    char choice;
    cout << "�������� ������ (r - �������������, t - �����������, c - ����): ";
    cin >> choice;

    while (choice != 'r' && choice != 't' && choice != 'c') {
        cout << "�������� �����." << endl;
        cout << "�������� ������ (r - �������������, t - �����������, c - ����): ";
        cin >> choice;
    }

    double length, width, base, height, radius;

    switch (choice) {
        case 'r':

            length = SafeNumberInput::positiveDouble("������� ����� ��������������: ");
            width = SafeNumberInput::positiveDouble("������� ������ ��������������: ");
            cout << "������� ��������������: " << length * width << endl;
            break;

        case 't':

            base = SafeNumberInput::positiveDouble("������� ��������� ������������: ");
            height = SafeNumberInput::positiveDouble("������� ������ ������������: ");
            cout << "������� ������������: " << 0.5 * base * height << endl;
            break;

        case 'c':

            radius = SafeNumberInput::positiveDouble("������� ������ �����: ");
            cout << "������� �����: " << M_PI * radius * radius << endl;
            break;
    }
}

inline void oldGlory() {
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 24; j++) {
            cout << ((i <= 6 and j <= 8) ? "* " : "--");
        }
        cout << "\n";
   }
}

inline void drawSinusoid() {
    
    int d = 0;
    cin >> d;
}


inline int getValue(char romanChar) {
    switch (romanChar) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

inline void romanToArabic() {
    string roman;
    cout << "������� ������� ������: ";
    cin >> roman;

    int result = 0;

    for (int i = 0; i < roman.size(); ++i) {
        if (i < roman.size() - 1 && getValue(roman[i]) < getValue(roman[i + 1])) {
            result -= getValue(roman[i]);
        } else {
            result += getValue(roman[i]);
        }
    }

    cout << "���������: " << result << endl;
}


inline void generateRandom() {
    int m1 = 37;
    int i1 = 3;
    int c1 = 64;

    int prevS1 = 1; // ��������� ��������
    int Si1 = 1; // ��������� ��������

    for (int i = 0; i < 10; ++i) {
        Si1 = (m1 * prevS1 + i1) % c1;
        cout << Si1 << endl;
        prevS1 = Si1;

    }


    int m2 = 25173;
    int i2 = 13849;
    int c2 = 65537;

    int prevS2 = 1; // ��������� ��������
    int Si2 = 1; // ��������� ��������

    for (int i = 0; i < 10; ++i) {
        Si2 = (m2 * prevS2 + i2) % c2;
        cout << Si2 << endl;
        prevS2 = Si2;

    }
}

inline void sales() {
    // ������� A - ���������� ��������� �������
    int A[3][4] = {
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0}
    };

    // ������� B - ���� ������� � ������������
    double B[4][2] = {
        {1.20, 0.50},
        {2.80, 0.40},
        {5.00, 1.00},
        {2.00, 1.50}
    };

    // ���������� ��� �����������
    double totalRevenue = 0;
    double totalCommission = 0;
    double maxRevenue = 0;
    double minRevenue = 1e12;
    int maxRevenueSeller = 0;
    int minRevenueSeller = 0;
    double maxCommission = 0;
    double minCommission = 1e12;
    int maxCommissionSeller = 0;
    int minCommissionSeller = 0;

    for (int i = 0; i < 3; ++i) {
        double revenue = 0;
        double commission = 0;

        for (int j = 0; j < 4; ++j) {
            revenue += A[i][j] * B[j][0]; // �������
            commission += A[i][j] * B[j][1]; // ������������
        }

        totalRevenue += revenue;
        totalCommission += commission;

        // ����� ���������� � ���������
        if (revenue > maxRevenue) {
            maxRevenue = revenue;
            maxRevenueSeller = i;
        }

        if (revenue < minRevenue) {
            minRevenue = revenue;
            minRevenueSeller = i;
        }

        if (commission > maxCommission) {
            maxCommission = commission;
            maxCommissionSeller = i;
        }

        if (commission < minCommission) {
            minCommission = commission;
            minCommissionSeller = i;
        }
    }

    // ����� �����������
    cout << "1) �������� " << maxRevenueSeller + 1 << " ������� ������ ����� �����: " << maxRevenue << endl;
    cout << "   �������� " << minRevenueSeller + 1 << " ������� ������ ����� �����: " << minRevenue << endl;
    cout << "2) �������� " << maxCommissionSeller + 1 << " ������� ���������� ������������: " << maxCommission << endl;
    cout << "   �������� " << minCommissionSeller + 1 << " ������� ���������� ������������: " << minCommission << endl;
    cout << "3) ����� ����� �����, ���������� �� ��������� ������: " << totalRevenue << endl;
    cout << "4) ������� ����� ������������ �������� ��������: " << totalCommission << endl;
    cout << "5) ����� ����� �����, ��������� ����� ���� ���������: " << totalRevenue + totalCommission << endl;

}

