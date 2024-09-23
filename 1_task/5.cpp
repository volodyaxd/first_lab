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
