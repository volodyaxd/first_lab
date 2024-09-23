#include <iostream>
#include <limits>
#include <windows.h>
using namespace std;

// Функция для вычисления модуля числа
int my_abs(int x) {
    return (x < 0) ? -x : x;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int number;

    // Проверка ввода
    cout << "Введите целое число: ";
    while (!(cin >> number)) {
        cout << "Ошибка ввода. Пожалуйста, введите целое число: ";
        cin.clear(); // Сброс состояния ввода 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
    }

    // Вызов функции my_abs и вывод результата
    cout << "Модуль числа " << number << " равен: " << my_abs(number) << endl;

    return 0;
}


// Examples
// Input: -5 Output: 5
// Input: papa Output: Ошибка ввода. Пожалуйста, введите целое число:
// Input: 4 Output: 4
// Input: 0 Output: 0
