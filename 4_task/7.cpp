#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

int* reverseBack(int arr[], int size) {
    // Создаем новый массив для reversed
    int* reversed = new int[size];

    // Заполняем его значениями из исходного массива в обратном порядке
    for (int i = 0; i < size; i++) {
        reversed[i] = arr[size - 1 - i];
    }

    return reversed; // Возвращаем указатель на новый массив
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int size;

    // Проверка на ввод размера массива
    cout << "Введите размер массива: ";
    cin >> size;

    // Проверка на корректность ввода
    while (size <= 0) {
        cout << "Размер массива должен быть положительным. Попробуйте снова: ";
        cin >> size;
    }

    int* arr = new int[size];

    // Ввод элементов массива
    cout << "Введите " << size << " элементов массива: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Вызов функции для реверсирования массива
    int* reversedArr = reverseBack(arr, size);

    // Вывод результата
    cout << "Массив в обратном порядке: [";
    for (int i = 0; i < size; i++) {
        cout << reversedArr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;

    // Освобождение памяти
    delete[] arr;
    delete[] reversedArr;

    return 0;
}
