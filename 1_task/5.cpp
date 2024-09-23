#include <iostream>
#include <windows.h>

bool is2Digits(int x) {
    return x >= 10 && x <= 99; // Проверка на двузначное число
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int number;

    std::cout << "Введите целое число: ";
    if (!(std::cin >> number)) {
        std::cout << "Ошибка ввода! Пожалуйста, введите целое число." << std::endl;
        return 1; // Завершаем программу с ошибкой
    }

    bool result = is2Digits(number);
    
    if (result) {
        std::cout << "Результат: true (число " << number << " двузначное)" << std::endl;
    } else {
        std::cout << "Результат: false (число " << number << " не двузначное)" << std::endl;
    }

    return 0; // Успешное завершение программы
}


// Examples
// Input: 1 Output: Результат: false (число 1 не двузначное)
// Input: 10 Output: Результат: true (число 10 двузначное)
// Input: ahting Output: Ошибка ввода! Пожалуйста, введите целое число.
// Input: 345 Output: Результат: false (число 345 не двузначное)
// Input: 1243546576980 Output: Ошибка ввода! Пожалуйста, введите целое число. (?)
// Input: 15 Output: Результат: true (число 15 двузначное)
