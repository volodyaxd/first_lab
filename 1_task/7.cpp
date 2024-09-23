#include <iostream>
#include <limits>
#include <windows.h>


bool isInRange(int a, int b, int num) {
    // Определяем минимальное и максимальное значение границ
    int min = a < b ? a : b; // Минимальная граница
    int max = a > b ? a : b; // Максимальная граница
    return (num >= min && num <= max); // Проверяем, входит ли num в диапазон
}

int inputInteger(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер
            return value; // Возвращаем корректное значение
        } else {
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число." << std::endl;
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Ввод границ диапазона
    int a = inputInteger("Введите левую границу (a): ");
    int b = inputInteger("Введите правую границу (b): ");
    
    // Ввод числа для проверки
    int num = inputInteger("Введите число для проверки (num): ");

    // Проверка, входит ли число в диапазон и вывод результата
    if (isInRange(a, b, num)) {
        std::cout << "Результат: true" << std::endl;
    } else {
        std::cout << "Результат: false" << std::endl;
    }

    return 0;
}


// Examples
// Input: a=1, b=10, num=4 Output: true
// Input: a=1, b=10, num=25 Output: false
// Input: a=-2, b=15, num=-1 Output: true
