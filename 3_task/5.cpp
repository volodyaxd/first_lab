#include <iostream>
#include <cstdlib> // Для функции abs
#include <limits>
#include <windows.h>

// Функция, возвращающая количество знаков в числе x
int numLen(long x) {
    if (x == 0) {
        return 1; // 0 состоит из одного знака
    }
    x = std::abs(x); // Приводим число к абсолютному значению
    int length = 0;

    while (x > 0) {
        x /= 10; // Уменьшаем число, деля на 10
        length++; // Увеличиваем счетчик разрядов
    }
    return length;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    long number;

    std::cout << "Введите число (например: 12567): ";
    while (true) {
        std::cin >> number; // Считываем число
        if (std::cin.fail()) { // Проверяем правильность ввода
            std::cin.clear(); // Очищаем состояние потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем некорректный ввод
            std::cout << "Некорректный ввод. Пожалуйста, введите число: ";
        } else {
            break; // Если ввод корректен, выходим из цикла
        }
    }

    // Вызываем функцию и выводим результат
    int length = numLen(number);
    std::cout << "Количество знаков в числе " << number << ": " << length << std::endl;

    return 0;
}


// Examples
// Input: 12567 Output: 5
// Input: 125-67 Output: 3
