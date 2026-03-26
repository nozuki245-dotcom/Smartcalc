#include <iostream>  // std::cin, std::cout
#include <cmath>     // pow()
#include <iomanip>   // std::fixed, std::setprecision

/*
    SmartCalc - консольный калькулятор в бесконечном цикле.

    Важные базовые пояснения:

    1) Зачем нужны ';' (точка с запятой):
       В C++ точка с запятой завершает инструкцию.
       Пример: double a = 5.0;
       Без ';' компилятор не поймет, где заканчивается команда.

    2) Зачем нужны '{}' (фигурные скобки):
       Скобки объединяют несколько инструкций в один блок.
       Например, тело цикла while или ветка case в switch.
       Это помогает задать границы кода и улучшает читаемость.

    3) Разница между double и int:
       - int хранит только целые числа (например, 3, -10, 42).
       - double хранит вещественные числа с дробной частью
         (например, 3.14, -0.5, 2.0).
       В калькуляторе удобно использовать double, чтобы работать
       не только с целыми, но и с дробными значениями.

    4) Как работают std::cin и std::cout:
       - std::cout выводит данные в консоль (на экран).
       - std::cin считывает данные, которые вводит пользователь.
       Оператор << "отправляет" данные в поток вывода,
       а оператор >> "извлекает" данные из потока ввода.
*/

int main() {
    // Форматируем числа в выводе: фиксированная запись и 2 знака после запятой.
    std::cout << std::fixed << std::setprecision(2);

    while (true) {
        double firstNumber = 0.0;
        double secondNumber = 0.0;
        char operation = '\0';
        double result = 0.0;

        std::cout << "\n=== SmartCalc ===\n";
        std::cout << "Введите первое число: ";
        std::cin >> firstNumber;

        // Проверка корректности ввода числа.
        if (!std::cin) {
            std::cout << "Ошибка: введено некорректное число.\n";
            break;
        }

        std::cout << "Введите оператор (+, -, *, /, ^): ";
        std::cin >> operation;

        std::cout << "Введите второе число: ";
        std::cin >> secondNumber;

        // Проверка корректности ввода числа.
        if (!std::cin) {
            std::cout << "Ошибка: введено некорректное число.\n";
            break;
        }

        bool operationSuccess = true;

        // Выбор операции через switch, как требуется.
        switch (operation) {
            case '+':
                result = firstNumber + secondNumber;
                break;

            case '-':
                result = firstNumber - secondNumber;
                break;

            case '*':
                result = firstNumber * secondNumber;
                break;

            case '/':
                // Безопасность: защита от деления на ноль.
                if (secondNumber == 0.0) {
                    std::cout << "Предупреждение: деление на ноль невозможно.\n";
                    operationSuccess = false;
                } else {
                    result = firstNumber / secondNumber;
                }
                break;

            case '^':
                // Возведение в степень через pow() из <cmath>.
                result = std::pow(firstNumber, secondNumber);
                break;

            default:
                std::cout << "Ошибка: неизвестный оператор.\n";
                operationSuccess = false;
                break;
        }

        if (operationSuccess) {
            std::cout << "Результат: " << result << "\n";
        }

        char continueAnswer = 'n';
        std::cout << "Продолжить? (y/n): ";
        std::cin >> continueAnswer;

        if (continueAnswer != 'y' && continueAnswer != 'Y') {
            std::cout << "Работа SmartCalc завершена.\n";
            break;
        }
    }

    return 0;
}
