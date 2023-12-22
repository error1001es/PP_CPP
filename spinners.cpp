#pragma once
#include <iostream>
#include "SafeNumberInput.cpp"

using namespace std;

inline void spinner1() {
    int A, B, C;

    A = SafeNumberInput::Int("Стоимость базы спиннера: ");

    B = SafeNumberInput::Int("Стоимость лопасти:  ");

    C = SafeNumberInput::Int("Максимальная стоимость: ");

    int blades = 0;
    int totalCost = A;

    while (true) {       
        totalCost = A + B * (blades + 1);

        if (totalCost > C) break;

        //cout << blades << endl;
        //cout << totalCost << endl;
        blades++;
    }
 
    cout << "Максимальное количество лопастей: " << blades << endl;
}

inline void spinner2() {
    int M = SafeNumberInput::Int("М: ");

    if (M % 3 == 0) {
        cout << "0 " << M / 3 << endl;
    }else if (M % 3 == 1) {
        if (M < 4) {
            cout << "0 0" << endl;
        }
        else {
            cout << "2 " << (M - 3 * 2) / 3 << endl;
        }
    }else if (M % 3 == 2) {
        cout << "1 " << (M - 4) / 3 << endl;
    }
}

inline void task3() {
    int M, N;

    M = SafeNumberInput::Int("Размер по первой стороне: ");
    N = SafeNumberInput::Int("Размер по второй стороне: ");

    long long rectangles = 0;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            rectangles += (M - i + 1) * (N - j + 1);
        }
    }

    cout << "Количество прямоугольников: " << rectangles << endl;
}

inline void task4() {
    int M = SafeNumberInput::Int("Кол-во свободных мест: ");

    int seats[9][6];
    for (int i = 0; i < 9; i++) {
        cout << "Купе " << i << " : ";

        seats[i][0] = 1 + 4 * i;
        seats[i][1] = seats[i][0] + 2;

        seats[i][2] = 2 + 4 * i;
        seats[i][3] = seats[i][2] + 2;

        seats[i][4] = 53 - 2 * i;
        seats[i][5] = 54 - 2 * i;

        for (int j = 0; j < 6; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < M; i++) {
        int seat = SafeNumberInput::Int("Введите место: ");
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 6; k++) {
                if (seats[j][k] == seat) {
                    seats[j][k] = 0;
                }
            }
        }
    }

    int count = 0;

    for (int j = 0; j < 9; j++) {
        int free = 1;
        for (int k = 0; k < 6; k++) {
            if (seats[j][k] != 0) {
                free = 0;
            }
        }
        if (free) {
            cout << "Купе #" << (j + 1) << " свободно" << endl;
            count++;
        }
    }

    cout << "Свободных купе: " << count;

}

inline void task5() {
    int n = SafeNumberInput::Int("N: ");
    int k = SafeNumberInput::Int("K: ");

    while (k != 1) {
        n = (n - k % 2) / 2;
        k = k / 2;
    }
    cout << (n - 1) / 2 << endl;
    cout << n / 2 << endl;;
}