#include <iostream>
#include <limits>
#include <windows.h>

double fraction(double x) {
    return x - static_cast<int>(x);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double input;

    std::cout << "Введите число: ";
    while (true) {
        std::cin >> input;
        
        if (std::cin.fail()) {
            std::cin.clear(); // Сбрасываем состояние потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем неверный ввод
            std::cout << "Ошибка ввода! Пожалуйста, введите вещественное число: ";
        } else {
            break; // Ввод корректен
        }
    }

    double result = fraction(input);
    std::cout << "Дробная часть числа " << input << " равна: " << result << std::endl;

    return 0;
}


// Examples
// input: papa Output: Ошибка ввода! Пожалуйста, введите вещественное число
// input: 5 Output: Дробная часть числа 5 равна: 0
// input: 5.7 Output: Дробная часть числа 5.7 равна: 0.7
