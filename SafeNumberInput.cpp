#pragma once
#include <iostream>
#include <limits>
#include <string>

// ������������ ���� ��� ����������� ����� �����
namespace SafeNumberInput {

    //const int maxBufferSize = std::numeric_limits<std::streamsize>::max();
    /*
        std::numeric_limits<std::streamsize>::max() ���������� ������������ ��������, 
        ������� ����� ���� ������������ ����� std::streamsize.
        ����� ������� �� ���������� ���� ��������� ���� ������������.
    */

    // ���� ������ ����� � ���������� ������
    inline int Int(const std::string& prompt = "") {
        int num;
        std::cout << prompt;
        // ���� ������������, ���� ���� �� �������� ����� ������
        while (!(std::cin >> num)) {
            std::cin.clear(); // ������� ����� ������ � ������ �����
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���������� ���� ���� �� ������� ����� ������
            std::cout << "�������� ����. \n" << prompt;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���������� ������ ����� ������ ����� ��������� �����
        return num;
    }

    // ���� �������������� ������ ����� � ���������� ������
    inline int positiveInt(const std::string& prompt = "") {
        int num = Int(prompt);
        // ���� ������������, ���� ���� �� �������� ������������� ����� ������
        while (num <= 0) {
            std::cout << "�������� ����. ����������, ������� ������������� ����� �����. \n";
            num = Int(prompt);
        }
        return num;
    }

    inline int zeroOrOne(const std::string& prompt = "") {
        int num = Int(prompt);
        // ���� ������������, ���� ���� �� �������� �� 1 �� 0
        while (num != 0 && num != 1) {
            std::cout << "�������� ����. ����������, ������� 1 ��� 0. \n";
            num = Int(prompt);
        }
        return num;
    }

    // ���� ����� � ��������� ������ � ���������� ������
    inline double Double(const std::string& prompt = "") {
        double num;
        std::cout << prompt;
        // ���� ������������, ���� ���� �� �������� ������ � ��������� ������
        while (!(std::cin >> num)) {
            std::cin.clear(); // ������� ����� ������ � ������ �����
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���������� ���� ���� �� ������� ����� ������
            std::cout << "�������� ����. \n" << prompt;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���������� ������ ����� ������ ����� ��������� �����
        return num;
    }

    // ���� �������������� ����� � ��������� ������ � ���������� ������
    inline double positiveDouble(const std::string& prompt = "") {
        double num = Double(prompt);
        // ���� ������������, ���� ���� �� �������� ������������� ������ � ��������� ������
        while (num <= 0) {
            std::cout << "�������� ����. ����������, ������� ������������� ����� � ��������� ������. \n";
            num = Double(prompt);
        }
        return num;
    }

}
