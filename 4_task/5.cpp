#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

int* add(int arr[], int arrSize, int ins[], int insSize, int pos) {
    // Проверка на валидность позиции
    if (pos < 0 || pos > arrSize) {
        cout << "Неверная позиция!" << endl;
        return nullptr;
    }

    // Создание нового массива
    int* newArr = new int[arrSize + insSize];

    // Копирование элементов до позиции вставки
    for (int i = 0; i < pos; i++) {
        newArr[i] = arr[i];
    }

    // Вставка новых элементов
    for (int i = 0; i < insSize; i++) {
        newArr[pos + i] = ins[i];
    }

    // Копирование оставшихся элементов
    for (int i = pos; i < arrSize; i++) {
        newArr[i + insSize] = arr[i];
    }

    return newArr;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int arrSize, insSize;

    cout << "Введите размер первого массива: ";
    cin >> arrSize;
    int* arr = new int[arrSize];

    cout << "Введите элементы первого массива: ";
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    cout << "Введите размер массива для вставки: ";
    cin >> insSize;
    int* ins = new int[insSize];

    cout << "Введите элементы массива для вставки: ";
    for (int i = 0; i < insSize; i++) {
        cin >> ins[i];
    }

    int pos;
    cout << "Введите позицию для вставки (0 до " << arrSize << "): ";
    cin >> pos;

    // Проверка на корректный ввод позиции
    while (cin.fail() || pos < 0 || pos > arrSize) {
        cin.clear(); // сброс ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера
        cout << "Неверный ввод. Пожалуйста, попробуйте снова: ";
        cin >> pos;
    }

    int* result = add(arr, arrSize, ins, insSize, pos);

    // Вывод результата
    cout << "Результат: [";
    for (int i = 0; i < arrSize + insSize; i++) {
        cout << result[i];
        if (i < arrSize + insSize - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Освобождение памяти
    delete[] arr;
    delete[] ins;
    delete[] result;
    
    return 0;
}
