#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

// Функция для поиска индекса первого вхождения числа x в массив arr
int findFirst(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i; // Возвращаем индекс первого вхождения
        }
    }
    return -1; // Если не найдено, возвращаем -1
}

// Функция для ввода массива
void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Главная функция
int main() {
    SetConsoleOutputCP(CP_UTF8);
    const int SIZE = 7;
    int arr[SIZE];
    int x;

    cout << "Введите элементы массива:" << endl;
    inputArray(arr, SIZE);

    cout << "Введите число для поиска: ";
    cin >> x;

    // Проверка на успешный ввод
    if (cin.fail()) {
        cout << "Некорректный ввод числа." << endl;
        return 1; // Выход из программы с ошибкой
    }

    int index = findFirst(arr, SIZE, x);
    
    if (index != -1) {
        cout << "Первое вхождение числа " << x << " находится по индексу: " << index << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}


// Examples
// Input: 1 2 3 4 5 6 7 and 4 Output: 3
// Input: 0 2 4 6 8 10 12 and 17 Output: 1
// Input: 0 2 4 6 8 10 12 and 12 Output: 6
// Input: 0 25 13 77 67 77 92 and 77 Output: 3
