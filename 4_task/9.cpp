#include <iostream>
#include <vector>
#include <limits>
#include <windows.h>
using namespace std;

int* findAll(int arr[], int size, int x, int& count) {
    vector<int> indices;

    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            indices.push_back(i);
        }
    }

    count = indices.size();
    int* result = new int[count];
    for (int i = 0; i < count; i++) {
        result[i] = indices[i];
    }
    
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size, x;

    cout << "Введите количество элементов массива (до 100): ";
    cin >> size;

    // Проверка на ввод корректного числа элементов
    while (size < 1 || size > MAX_SIZE) {
        cout << "Ошибка! Введите количество элементов от 1 до 100: ";
        cin >> size;
    }

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Введите число x для поиска: ";
    cin >> x;

    int count;
    int* indices = findAll(arr, size, x, count);

    cout << "Индексы всех вхождений числа " << x << ": ";
    for (int i = 0; i < count; i++) {
        cout << indices[i] << (i < count - 1 ? ", " : "");
    }
    cout << endl;

    delete[] indices; // Освобождение памяти
    return 0;
}
