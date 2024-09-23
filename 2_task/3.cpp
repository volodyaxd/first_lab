#include <iostream>
#include <limits>
#include <windows.h>
using namespace std;

bool is35(int x) {
    if (x % 3 == 0 && x % 5 == 0) {
        return false;
    }
    return (x % 3 == 0 || x % 5 == 0);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int x;

    cout << "Введите число: ";
    while (!(cin >> x)) {
        cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
        cin.clear(); // Очистка флага ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирование некорректного ввода
    }

    bool result = is35(x);
    cout << "Результат: " << boolalpha << result << endl;

    return 0;
}


// Examples
// Input: 15 Output: false
// Input: 3 Output: true
// Input: -5 Output: true
// Input: papa : Output: Некорректный ввод. Пожалуйста, введите целое число:
