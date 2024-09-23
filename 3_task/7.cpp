#include <iostream>
#include <limits>
#include <windows.h>
using namespace std;

// Функция для вывода квадрата из символов '*'
void square(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << "*";
        }
        cout << endl; // Переход на новую строку после заполнения строки квадратом
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int x;

    // Организация ввода с проверкой
    cout << "Введите размер квадрата (положительное целое число): ";
    while (true) {
        cin >> x;
        if (cin.fail() || x <= 0) { // Проверка на корректность ввода
            cin.clear(); // Очищаем состояние ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем неправильный ввод
            cout << "Ошибка. Пожалуйста, введите положительное целое число: ";
        } else {
            break; // Ввод корректен, выходим из цикла
        }
    }

    // Вызов функции для построения квадрата
    square(x);

    return 0;
}


// Examples
// Input: 1 Output: *
// Input: 2 Output: **
//                  **
// Input: 6 Output: ******
//                  ******
//                  ******
//                  ******
//                  ******
//                  ******
// Input: -2 Output: Ошибка. Пожалуйста, введите положительное целое число:
