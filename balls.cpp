#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;

// Функция, которая генерирует перестановки и проверяет условие
inline void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Функция для генерации перестановок
inline void permutation(int arr[], int n, int i, int j, int& count, bool needPrint = false) {
    int k;
    if (i == n) {
        // Проверяем, удовлетворяет ли текущая перестановка условию
        for (k = 1; k < n; k++) {
            if (k == arr[k - 1]) {
                count++;
            }

            if(needPrint)   cout << arr[k-1] << " ";
        }
        if (needPrint)  cout << endl;
    }
    else {
        for (k = i; k < n; k++) {
            swap(arr, i, k);
            permutation(arr, n, i + 1, k, count, needPrint);
            swap(arr, i, k);
        }
    }
}

inline int factorial(int i)
{
    if (i == 0) return 1;
    else return i * factorial(i - 1);
}

// Функция, которая демонстрирует работу генерации перестановок
inline void balls(bool needPrint = false) {
    int n = 10;
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

    int count = 0;
    permutation(arr, n, 0, 0, count, needPrint);
    const int permutationCount = factorial(10);

    cout << "Количество перестановок, удовлетворяющих условию: " << count << " из " << permutationCount << " | ";

    double result = static_cast<double>(count) / permutationCount * 100;

    cout << result << "%" << endl;
}