#include <iostream>
#include <limits>
#include <windows.h>

bool isEqual(int a, int b, int c) {
    return (a == b) && (b == c);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int a, b, c;

    // Функция ввода с проверкой
    auto getInput = [](const std::string& prompt) -> int {
        int value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;

            // Проверка на корректный ввод
            if (std::cin.fail()) {
                std::cout << "Некорректный ввод. Пожалуйста, введите целое число." << std::endl;
                std::cin.clear(); // Сброс состояния флага ошибки
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
                return value;
            }
        }
    };

    // Ввод трех чисел от пользователя
    a = getInput("Введите первое число (a): ");
    b = getInput("Введите второе число (b): ");
    c = getInput("Введите третье число (c): ");

    // Вызов функции и вывод результата
    bool result = isEqual(a, b, c);
    std::cout << "Результат: " << std::boolalpha << result << std::endl;

    return 0;
}


// Examples
// Input: a=1, b=1, c=1 Output: true
// Input: a=-1, b=-1, c=-1 Output: true
// Input: a='1', b='1', c='1' Output: При вводе 'a' выводит: Некорректный ввод. Пожалуйста, введите целое число. и снова запрашивает ввод 'a'
// Input: a=1, b=2, c=3 Output: false
// Input: a=-1, b=1, c=-1 Output: false
