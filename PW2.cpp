#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "SafeNumberInput.cpp"

using namespace std;


inline void calculateConus() {
    // ���� �������� ������ � ����������
    double R = SafeNumberInput::positiveDouble("������� ������ �������� ��������� R: ");
    double r = SafeNumberInput::positiveDouble("������� ������ �������� ��������� r: ");
    double h = SafeNumberInput::positiveDouble("������� ������ h: ");

    if (R > r /* h ��� > 0 */) {
        // ���������� ������ � ������ ����������� ���������� ������
        double volume = (1.0 / 3.0) * M_PI * h * (R * R + R * r + r * r);
        double l = sqrt((R - r) * (R - r) + h * h); // ��������� ���������� ������
        double surfaceArea = M_PI * (R * R + (R + r) * l + r * r);

        // ����� �����������
        cout << "����� ���������� ������: " << volume << endl;
        cout << "������ ����������� ���������� ������: " << surfaceArea << endl;
    }
    else {
        cout << "������ ������ �� ����������" << endl;
    }
   
}

inline void branch() {
    double x = SafeNumberInput::Double("������� �������� x: ");
    double a = SafeNumberInput::Double("������� �������� a: ");

    // ���������� ���������� � ����������� �� �������
    double result;
    if (abs(x) < 1) {
        // ���� |x| < 1, �� a * ln(|x|)
        result = a * log(abs(x));
    }
    else {
        // ���� |x| >= 1, �� ���������� ������(a - x^2)
        if ((a - x * x) >= 0) {
            result = sqrt(a - x * x);
        }  else {
            cout << "������ �� �������������� ����� ��� �������� :)" << endl;
            return;
        }
    }

    // ����� ����������
    cout << "���������: " << result << endl;
}

inline void function() {
    // ���� x, y � b � �������������� SafeNumberInput
    double x = SafeNumberInput::Double("������� �������� x: ");
    double y = SafeNumberInput::Double("������� �������� y: ");
    double b = SafeNumberInput::Double("������� �������� b: ");

    // ���������� ������� z = ln(b-y)*sqrt(b-x)
    if (((b - y) > 0) && ((b - x) >= 0)) {
        double result = log(b - y) * sqrt(b - x);

        // ����� ����������
        cout << "��������� �������: " << result << endl;
    }
    else {
        cout << "ln �� ����� <= 0 �� ����������, ��� �� ��� � �����" << endl;
    }
   
}

inline void order() {
    int n = SafeNumberInput::Int("������� �������� n: ");

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