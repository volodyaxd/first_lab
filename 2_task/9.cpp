#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

// Функция для определения дня недели
std::string day(int x) {
    switch (x) {
        case 1: return "понедельник";
        case 2: return "вторник";
        case 3: return "среда";
        case 4: return "четверг";
        case 5: return "пятница";
        case 6: return "суббота";
        case 7: return "воскресенье";
        default: return "это не день недели";
    }
}

// Функция для проверки ввода данных
int getInput() {
    int x;
    while (true) {
        std::cout << "Введите номер дня недели (1-7): ";
        std::cin >> x;

        if (std::cin.fail()) {
            std::cin.clear(); // сброс состояния cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорировать неправильный ввод
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число от 1 до 7." << std::endl;
        } else if (x < 1 || x > 7) {
            std::cout << "Пожалуйста, введите число от 1 до 7." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорировать оставшиеся символы в буфере
            return x;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int dayNumber = getInput(); // Получаем ввод от пользователя
    std::string dayName = day(dayNumber); // Вызываем функцию для определения дня недели
    std::cout << "День недели: " << dayName << std::endl; // Выводим результат
    return 0;
}


// Examples
// Input: 1-7 Output: Понедельник-Воскресенье
// Input: 8 Output: Пожалуйста, введите число от 1 до 7
// Input: papa Output: Некорректный ввод. Пожалуйста, введите целое число от 1 до 7.
