#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <windows.h>

std::string chet(int x) {
    std::ostringstream result;
    for (int i = 0; i <= x; i += 2) {
        result << i << " ";
    }
    return result.str();
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int x;
    std::cout << "Введите число: ";
    while (!(std::cin >> x)) {
        std::cout << "Ошибка ввода. Пожалуйста, введите целое число: ";
        std::cin.clear(); // Сброс флага ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка ввода
    }

    std::string результат = chet(x);
    std::cout << "Результат: " << результат << std::endl;

    return 0;
}


// Examples
// Input: 15 Output: 0 2 4 6 8 10 12 14
// Input: -2 Output: 
// Input: 2 Output: 0 2
