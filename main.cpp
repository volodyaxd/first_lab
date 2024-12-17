#include <iostream>
#include <limits>
#include <windows.h>
#include <cctype>
#include <string>
#include <sstream>
#include <cstdlib>

double fraction(double x) {
    return x - static_cast<int>(x);
}

void fractional_part() {
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


}

using namespace std;

int charToNum(char x) {
    if (x >= '0' && x <= '9') {
        return x - '0'; // Преобразуем символ в соответствующее число
    } else {
        throw invalid_argument("Некорректный символ! Введите цифру от 0 до 9.");
    }
}

void letter_to_number() {
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


}

bool is2Digits(int x) {
    return x >= 10 && x <= 99; // Проверка на двузначное число
}

void two_digit() {
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

bool isInRange(int a, int b, int num) {
    // Определяем минимальное и максимальное значение границ
    int min = a < b ? a : b; // Минимальная граница
    int max = a > b ? a : b; // Максимальная граница
    return (num >= min && num <= max); // Проверяем, входит ли num в диапазон
}

int inputInteger(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер
            return value; // Возвращаем корректное значение
        } else {
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число." << std::endl;
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер
        }
    }
}

void diaposon() {
    // Ввод границ диапазона
    int a = inputInteger("Введите левую границу (a): ");
    int b = inputInteger("Введите правую границу (b): ");
    
    // Ввод числа для проверки
    int num = inputInteger("Введите число для проверки (num): ");

    // Проверка, входит ли число в диапазон и вывод результата
    if (isInRange(a, b, num)) {
        std::cout << "Результат: true" << std::endl;
    } else {
        std::cout << "Результат: false" << std::endl;
    }

}

bool isEqual(int a, int b, int c) {
    return (a == b) && (b == c);
}

void equality() {
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


}

using namespace std;

// Функция для вычисления модуля числа
int my_abs(int x) {
    return (x < 0) ? -x : x;
}

void number_modulus() {
    int number;

    // Проверка ввода
    cout << "Введите целое число: ";
    while (!(cin >> number)) {
        cout << "Ошибка ввода. Пожалуйста, введите целое число: ";
        cin.clear(); // Сброс состояния ввода 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
    }

    // Вызов функции my_abs и вывод результата
    cout << "Модуль числа " << number << " равен: " << my_abs(number) << endl;


}

using namespace std;

bool is35(int x) {
    if (x % 3 == 0 && x % 5 == 0) {
        return false;
    }
    return (x % 3 == 0 || x % 5 == 0);
}

void thirty_five() {
    int x;

    cout << "Введите число: ";
    while (!(cin >> x)) {
        cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
        cin.clear(); // Очистка флага ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирование некорректного ввода
    }

    bool result = is35(x);
    cout << "Результат: " << boolalpha << result << endl;


}

int max3(int x, int y, int z) {
    return (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
}

void triple_max() {
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


}

int sum2(int x, int y) {
    int sum = x + y;
    // Возвращаем 20, если сумма находится в диапазоне от 10 до 19
    if (sum >= 10 && sum <= 19) {
        return 20;
    }
    return sum;
}

void double_sum() {
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

}

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

void week_day() {
    int dayNumber = getInput(); // Получаем ввод от пользователя
    std::string dayName = day(dayNumber); // Вызываем функцию для определения дня недели
    std::cout << "День недели: " << dayName << std::endl; // Выводим результат

}

std::string listNums(int x) {
    std::ostringstream result;  // Для формирования строки
    for (int i = 0; i <= x; ++i) {
        result << i;  // Добавляем текущее число
        if (i < x) {
            result << " ";  // Добавляем пробел между числами, если это не последнее число
        }
    }
    return result.str();  // Возвращаем сформированную строку
}

void consecutive_numbers() {
    int x;

    std::cout << "Введите неотрицательное число: ";
    while (true) {
        std::cin >> x;
        if (std::cin.fail() || x < 0) { // Проверка на ввод
            std::cin.clear(); // Сбрасываем состояние
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем поток
            std::cout << "Ошибка ввода. Пожалуйста, введите неотрицательное число: ";
        } else {
            break; // Выход из цикла, если ввод корректен
        }
    }

    std::string result = listNums(x);
    std::cout << "Результат: \"" << result << "\"" << std::endl;


}

std::string chet(int x) {
    std::ostringstream result;
    for (int i = 0; i <= x; i += 2) {
        result << i << " ";
    }
    return result.str();
}

void even_numbers() {
    int x;
    std::cout << "Введите число: ";
    while (!(std::cin >> x)) {
        std::cout << "Ошибка ввода. Пожалуйста, введите целое число: ";
        std::cin.clear(); // Сброс флага ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка ввода
    }

    std::string результат = chet(x);
    std::cout << "Результат: " << результат << std::endl;


}

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

void number_length() {
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


}

using namespace std;

// Функция для вывода квадрата из символов '*'
void square(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << "*";
        }
        cout << endl; // Переход на новую строку после заполнения строки квадратом
    }
}

void square_main() {
    int x;

    // Организация ввода с проверкой
    cout << "Введите размер квадрата (положительное целое число): ";
    while (true) {
        cin >> x;
        if (cin.fail() || x <= 0) { // Проверка на корректность ввода
            cin.clear(); // Очищаем состояние ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем неправильный ввод
            cout << "Ошибка. Пожалуйста, введите положительное целое число: ";
        } else {
            break; // Ввод корректен, выходим из цикла
        }
    }

    // Вызов функции для построения квадрата
    square(x);

}

void rightTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        // Вывод пробелов
        for (int j = 0; j < x - i; ++j) {
            std::cout << ' ';
        }
        // Вывод звездочек
        for (int k = 0; k < i; ++k) {
            std::cout << '*';
        }
        std::cout << std::endl; // Переход на новую строку
    }
}

void right_triangle() {
    int height;

    std::cout << "Введите высоту треугольника (положительное число): ";
    while (true) {
        std::cin >> height;
        if (std::cin.fail() || height <= 0) {
            std::cout << "Ошибка ввода! Пожалуйста, введите положительное число: ";
            std::cin.clear(); // Сброс флага ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка входного потока
        } else {
            break; // Ввод корректен, выход из цикла
        }
    }

    rightTriangle(height); // Вызов функции для вывода треугольника


}

using namespace std;

// Функция для поиска индекса первого вхождения числа x в массив arr
int findFirst(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i; // Возвращаем индекс первого вхождения
        }
    }
    return -1; // Если не найдено, возвращаем -1
}

// Функция для ввода массива
void inputArray1(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Главная функция
void first_value_search() {
    const int SIZE = 7;
    int arr[SIZE];
    int x;

    cout << "Введите элементы массива:" << endl;
    inputArray1(arr, SIZE);

    cout << "Введите число для поиска: ";
    cin >> x;

    // Проверка на успешный ввод
    if (cin.fail()) {
        cout << "Некорректный ввод числа." << endl;
        return 1; // Выход из программы с ошибкой
    }

    int index = findFirst(arr, SIZE, x);
    
    if (index != -1) {
        cout << "Первое вхождение числа " << x << " находится по индексу: " << index << endl;
    } else {
        cout << 1 << endl;
    }

}

int maxAbs(int arr[], int size) {
    int max_value = arr[0];

    for (int i = 1; i < size; i++) {
        if (std::abs(arr[i]) > std::abs(max_value)) {
            max_value = arr[i];
        }
    }
    return max_value;
}

// Функция для ввода значений массива с проверкой
void inputArray2(int arr[], int &size) {
    std::cout << "Введите количество элементов массива: ";
    std::cin >> size;

    while (size <= 0) {
        std::cout << "Количество элементов должно быть положительным. Попробуйте снова: ";
        std::cin >> size;
    }

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void search_max() {
    const int maxSize = 100; // Максимальный размер массива
    int arr[maxSize];
    int size = 0;

    // Ввод массива
    inputArray2(arr, size);

    // Нахождение и вывод наибольшего по модулю значения
    int result = maxAbs(arr, size);
    std::cout << "Наибольшее по модулю значение: " << result << std::endl;


}

using namespace std;

int* add(int arr[], int arrSize, int ins[], int insSize, int pos) {
    // Проверка на валидность позиции
    if (pos < 0 || pos > arrSize) {
        cout << "Неверная позиция!" << endl;
        return nullptr;
    }

    // Создание нового массива
    int* newArr = new int[arrSize + insSize];

    // Копирование элементов до позиции вставки
    for (int i = 0; i < pos; i++) {
        newArr[i] = arr[i];
    }

    // Вставка новых элементов
    for (int i = 0; i < insSize; i++) {
        newArr[pos + i] = ins[i];
    }

    // Копирование оставшихся элементов
    for (int i = pos; i < arrSize; i++) {
        newArr[i + insSize] = arr[i];
    }

    return newArr;
}

void array_addition() {
    int arrSize, insSize;

    cout << "Введите размер первого массива: ";
    cin >> arrSize;
    int* arr = new int[arrSize];

    cout << "Введите элементы первого массива: ";
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    cout << "Введите размер массива для вставки: ";
    cin >> insSize;
    int* ins = new int[insSize];

    cout << "Введите элементы массива для вставки: ";
    for (int i = 0; i < insSize; i++) {
        cin >> ins[i];
    }

    int pos;
    cout << "Введите позицию для вставки (0 до " << arrSize << "): ";
    cin >> pos;

    // Проверка на корректный ввод позиции
    while (cin.fail() || pos < 0 || pos > arrSize) {
        cin.clear(); // сброс ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера
        cout << "Неверный ввод. Пожалуйста, попробуйте снова: ";
        cin >> pos;
    }

    int* result = add(arr, arrSize, ins, insSize, pos);

    // Вывод результата
    cout << "Результат: [";
    for (int i = 0; i < arrSize + insSize; i++) {
        cout << result[i];
        if (i < arrSize + insSize - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Освобождение памяти
    delete[] arr;
    delete[] ins;
    delete[] result;
    
}

using namespace std;

int* reverseBack(int arr[], int size) {
    // Создаем новый массив для reversed
    int* reversed = new int[size];

    // Заполняем его значениями из исходного массива в обратном порядке
    for (int i = 0; i < size; i++) {
        reversed[i] = arr[size - 1 - i];
    }

    return reversed; // Возвращаем указатель на новый массив
}

void reverse_gear() {
    int size;

    // Проверка на ввод размера массива
    cout << "Введите размер массива: ";
    cin >> size;

    // Проверка на корректность ввода
    while (size <= 0) {
        cout << "Размер массива должен быть положительным. Попробуйте снова: ";
        cin >> size;
    }

    int* arr = new int[size];

    // Ввод элементов массива
    cout << "Введите " << size << " элементов массива: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Вызов функции для реверсирования массива
    int* reversedArr = reverseBack(arr, size);

    // Вывод результата
    cout << "Массив в обратном порядке: [";
    for (int i = 0; i < size; i++) {
        cout << reversedArr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;

    // Освобождение памяти
    delete[] arr;
    delete[] reversedArr;


}

using namespace std;

int* findAll(int arr[], int size, int x, int& count) {
    vector<int> indices;

    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            indices.push_back(i);
        }
    }

    count = indices.size();
    int* result = new int[count];
    for (int i = 0; i < count; i++) {
        result[i] = indices[i];
    }
    
    return result;
}

void all_occurrences() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size, x;

    cout << "Введите количество элементов массива (до 100): ";
    cin >> size;

    // Проверка на ввод корректного числа элементов
    while (size < 1 || size > MAX_SIZE) {
        cout << "Ошибка! Введите количество элементов от 1 до 100: ";
        cin >> size;
    }

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Введите число x для поиска: ";
    cin >> x;

    int count;
    int* indices = findAll(arr, size, x, count);

    cout << "Индексы всех вхождений числа " << x << ": ";
    for (int i = 0; i < count; i++) {
        cout << indices[i] << (i < count - 1 ? ", " : "");
    }
    cout << endl;

    delete[] indices; // Освобождение памяти
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;

    do {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Дробная часть\n";
        std::cout << "2. Букву в число\n";
        std::cout << "3. Двузначное\n";
        std::cout << "4. Диапозон\n";
        std::cout << "5. Равенство\n";
        std::cout << "6. Модуль числа\n";
        std::cout << "7. Тридцать пять\n";
        std::cout << "8. Тройной максимум\n";
        std::cout << "9. Двойная сумма\n";
        std::cout << "10. День недели\n";
        std::cout << "11. Числа подряд\n";
        std::cout << "12. Чётные числа\n";
        std::cout << "13. Длина числа\n";
        std::cout << "14. Квадрат\n";
        std::cout << "15. Правый треугольник\n";
        std::cout << "16. Поиск первого значения\n";
        std::cout << "17. Поиск максимального\n";
        std::cout << "18. Добавление массива в массив\n";
        std::cout << "19. Возвратный реверс\n";
        std::cout << "20. Все вхождения\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                fractional_part();
                break;
            case 2:
                letter_to_number();
                break;
            case 3:
                two_digit();
                break;
            case 4:
                diaposon();
                break;
            case 5:
                equality();
                break;
            case 6:
                number_modulus();
                break;
            case 7:
                thirty_five();
                break;
            case 8:
                triple_max();
                break;
            case 9:
                double_sum();
                break;
            case 10:
                week_day();
                break;
            case 11:
                consecutive_numbers();
                break;
            case 12:
                even_numbers();
                break;
            case 13:
                number_length();
                break;
            case 14:
                square_main();
                break;
            case 15:
                right_triangle();
                break;
            case 16:
                first_value_search();
                break;
            case 17:
                search_max();
                break;
            case 18:
                array_addition();
                break;
            case 19:
                reverse_gear();
                break;
            case 20:
                all_occurrences();
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор, попробуйте снова." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
