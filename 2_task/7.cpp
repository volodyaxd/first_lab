#include <iostream>
#include <limits>
#include <windows.h>

int sum2(int x, int y) {
    int sum = x + y;
    // Возвращаем 20, если сумма находится в диапазоне от 10 до 19
    if (sum >= 10 && sum <= 19) {
        return 20;
    }
    return sum;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int x, y;

    // Проверка ввода для x
    std::cout << "Введите число x: ";
    while (!(std::cin >> x)) {
        std::cout << "Неверный ввод. Пожалуйста, введите целое число для x: ";
        std::cin.clear(); // Сбросить состояние потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорировать оставшийся ввод
    }

    // Проверка ввода для y
    std::cout << "Введите число y: ";
    while (!(std::cin >> y)) {
        std::cout << "Неверный ввод. Пожалуйста, введите целое число для y: ";
        std::cin.clear(); // Сбросить состояние потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорировать оставшийся ввод
    }

    // Вызываем функцию sum2 и выводим результат
    int result = sum2(x, y);
    std::cout << "Результат: " << result << std::endl;

    return 0;
}


// Examples
// Input: x=10, y=9 Output: 20
// Input: x=8, y=1 Output: 9
// Input: x=2, y=8 Output: 20
// Input: x=-5, y=-5 Output: -10
// Input: x=papa Output: Неверный ввод. Пожалуйста, введите целое число для x
// Input: x=10, y=papa Output: Неверный ввод. Пожалуйста, введите целое число для x
// Input: x=15, y=6 Output: 21
