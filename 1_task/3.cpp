#include <iostream>
#include <cctype>
#include <windows.h>

using namespace std;

int charToNum(char x) {
    if (x >= '0' && x <= '9') {
        return x - '0'; // Преобразуем символ в соответствующее число
    } else {
        throw invalid_argument("Некорректный символ! Введите цифру от 0 до 9.");
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char inputChar;

    // Ввод символа с проверкой
    cout << "Введите символ от '0' до '9': ";
    cin >> inputChar;

    try {
        int result = charToNum(inputChar);
        cout << "Результат: " << result << endl; // Вывод результата
    } catch (const invalid_argument& e) {
        cout << e.what() << endl; // Вывод сообщения об ошибке
    }

    return 0;
}


// Examples
// Input: 0 Output: 0
// Input: '9' Output: Некорректный символ! Введите цифру от 0 до 9.
// Input: papa Output: Некорректный символ! Введите цифру от 0 до 9.
