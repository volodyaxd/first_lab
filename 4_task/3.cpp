#include <iostream>
#include <cstdlib> // Для функции abs
#include <limits>
#include <windows.h>

// Функция для нахождения наибольшего по модулю значения в массиве
int maxAbs(int arr[], int size) {
    int max_value = arr[0];

    for (int i = 1; i < size; i++) {
        if (std::abs(arr[i]) > std::abs(max_value)) {
            max_value = arr[i];
        }
    }
    return max_value;
}

// Функция для ввода значений массива с проверкой
void inputArray(int arr[], int &size) {
    std::cout << "Введите количество элементов массива: ";
    std::cin >> size;

    while (size <= 0) {
        std::cout << "Количество элементов должно быть положительным. Попробуйте снова: ";
        std::cin >> size;
    }

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const int maxSize = 100; // Максимальный размер массива
    int arr[maxSize];
    int size = 0;

    // Ввод массива
    inputArray(arr, size);

    // Нахождение и вывод наибольшего по модулю значения
    int result = maxAbs(arr, size);
    std::cout << "Наибольшее по модулю значение: " << result << std::endl;

    return 0;
}


// Examples
// Input: 5 and 1 2 3 4 5 Output: 5
// Input: 5 and 0 -500 500 1000 -100000 Output: -100000
// Input: 4 and 0 -500 500 1000 Output: 1000
