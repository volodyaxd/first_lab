#include <iostream>
#include <limits>
#include <windows.h>

void rightTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        // Вывод пробелов
        for (int j = 0; j < x - i; ++j) {
            std::cout << ' ';
        }
        // Вывод звездочек
        for (int k = 0; k < i; ++k) {
            std::cout << '*';
        }
        std::cout << std::endl; // Переход на новую строку
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int height;

    std::cout << "Введите высоту треугольника (положительное число): ";
    while (true) {
        std::cin >> height;
        if (std::cin.fail() || height <= 0) {
            std::cout << "Ошибка ввода! Пожалуйста, введите положительное число: ";
            std::cin.clear(); // Сброс флага ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка входного потока
        } else {
            break; // Ввод корректен, выход из цикла
        }
    }

    rightTriangle(height); // Вызов функции для вывода треугольника

    return 0;
}


// Examples
// Input: 3 Output: *
//                 **
//                ***
// Input: 5 Output: *
//                 **
//                ***
//               ****
//              *****
// Input: -2 Output: Ошибка ввода! Пожалуйста, введите положительное число:
