#pragma once
#include <iostream>
#include "SafeNumberInput.cpp"

using namespace std;

inline void name() {
    cout << "����";
}

inline void arithmetic() {
    // ���� ���� ����� � ����������
    double num1, num2;
    num1 = SafeNumberInput::Double("������� ������ �����: ");
    num2 = SafeNumberInput::Double("������� ������ �����: ");

    // ���������� � ����� �����������
    cout << "�����: " << num1 + num2 << endl;
    cout << "��������: " << num1 - num2 << endl;
    cout << "������������: " << num1 * num2 << endl;

    // �������� �� ����, ����� �������� ������� �� ����
    if (num2 != 0) {
        cout << "�������: " << num1 / num2 << endl;
    }
    else {
        cout << "���������� ��������� �������, ��� ��� �������� ����� ����." << endl;
    }
}

inline void solveEquation() {
    // ���� ������������� b � c � ����������
    double b, c;
    b = SafeNumberInput::Double("������� ����������� b: ");
    c = SafeNumberInput::Double("������� ����������� c: ");

    // ��������, �������� �� ��������� ����������� (b = 0)
    if (b == 0) {
        if (c == 0) {
            cout << "��������� ����� ����������� ��������� �������." << endl;
        } else {
            cout << "��������� �� ����� �������." << endl;
        }
    } else {
        // ������� ��������� � ����� ����������
        double x = -c / b;
        cout << "������� ��������� " << b << "x + " << c << " = 0" << endl;
        cout << "x = " << x << endl;
    }
}

inline void solveQuadraticEquation() {
    // ���� ������������� a, b � c � ����������
    double a = SafeNumberInput::Double("������� ����������� a: ");
    double b = SafeNumberInput::Double("������� ����������� b: ");
    double c = SafeNumberInput::Double("������� ����������� c: ");

    // ���������� �������������
    double discriminant = b * b - 4 * a * c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "��������� ����� ����������� ��������� �������." << endl;
            }
            else {
                cout << "��������� �� ����� �������." << endl;
            }
        }
        else {
            // ������� ��������� � ����� ����������
            double x = -c / b;
            cout << "������� ��������� " << b << "x + " << c << " = 0" << endl;
            cout << "x = " << x << endl;
        }
    }
    else {
        if (discriminant > 0) {
            // ��� �������������� �����
            double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
            double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
            cout << "��������� ����� ��� �������������� �����: x1 = " << root1 << ", x2 = " << root2 << std::endl;
        }
        else if (discriminant == 0) {
            // ���� �������������� ������
            double root = -b / (2 * a);
            cout << "��������� ����� ���� �������������� ������: x = " << root << std::endl;
        }
        else {
            // ��� ����������� �����
            double realPart = -b / (2 * a);
            double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
            cout << "��������� ����� ��� ����������� �����: x1 = " << realPart << " + " << imaginaryPart << "i, x2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
        }
    }
}

inline void isRoomBright() {
    bool isDaytime = SafeNumberInput::zeroOrOne("�� ����� ����? 1 - ��, 0 - ���\n");
    bool areCurtainsOpen = SafeNumberInput::zeroOrOne("����� �������? 1 - ��, 0 - ���\n");
    bool isLampOn = SafeNumberInput::zeroOrOne("����� ��������? 1 - ��, 0 - ���\n");


    bool isRoomBright = (isDaytime && areCurtainsOpen) || isLampOn;

    cout << "� ������� ������ " << (isRoomBright ? "������" : "�����");
}