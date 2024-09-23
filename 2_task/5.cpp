#include <iostream>
#include <limits>
#include <windows.h>

int max3(int x, int y, int z) {
    return (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int x, y, z;

    // Запрос ввод значений
    std::cout << "Введите три целых числа (x, y, z): " << std::endl;

    while (true) {
        std::cout << "x: ";
        std::cin >> x;
        std::cout << "y: ";
        std::cin >> y;
        std::cout << "z: ";
        std::cin >> z;

        // Проверка на ввод
        if (std::cin.fail()) {
            std::cin.clear(); // очистка флага ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорируем неправильный ввод
            std::cout << "Ошибка: пожалуйста, введите целые числа." << std::endl;
        } else {
            break; // выход из цикла, если ввод успешный
        }
    }

    // Вызов функции и вывод результата
    int result = max3(x, y, z);
    std::cout << "Максимальное значение: " << result << std::endl;

    return 0;
}


// Examples
// Input: x=-1, y=-2, z=-3 Output: Максимальное значение: -1
// Input: x=papa Output: y: z: Ошибка: пожалуйста, введите целые числа.
// Input: x=1.0 Output: y: z: Ошибка: пожалуйста, введите целые числа.
// Input: x=1, y=150, z=-600 Output: Максимальное значение: 150
