# IntegerMath

Header-only библиотека для выполнения арифметических операций с проверкой переполнения.
Все операции возвращают результат типа `double` или бросают исключение при ошибке.
Для успешной сборки необходим компилятор с поддержкой C++17 или новее.

## Пример использования

```cpp
#include <integermath/integermath.h>
#include <cstdio>
#include <stdexcept>

int main() {
    integermath::CalculationModule<int> calc;

    // Сложение
    calc.SetLeftNumber(100);
    calc.SetRightNumber(200);
    printf("100 + 200 = %.0f\n", calc.sum());

    // Умножение с проверкой переполнения
    try {
        calc.SetLeftNumber(1000000);
        calc.SetRightNumber(3000000);
        printf("1000000 * 3000000 = %.0f\n", calc.multiply());
    } catch (const std::overflow_error& e) {
        printf("Переполнение: %s\n", e.what());
    }

    // Деление
    calc.SetLeftNumber(10);
    calc.SetRightNumber(3);
    printf("10 / 3 = %f\n", calc.divide());

    // Возведение в степень
    calc.SetLeftNumber(2);
    calc.SetRightNumber(10);
    printf("2^10 = %.0f\n", calc.power());

    // Факториал (использует только левый операнд)
    calc.SetLeftNumber(5);
    printf("5! = %.0f\n", calc.factorial());

    return 0;
}
```

## API

Все операции реализованы в шаблонном классе `CalculationModule<T>`.

### Установка операндов

```cpp
void SetLeftNumber(T number);   // левый операнд
void SetRightNumber(T number);  // правый операнд
```

### Получение операндов

```cpp
T getLeftNumber();
T getRightNumber();
```

### Арифметические операции

| Метод | Описание | Операнды |
|---|---|---|
| `double sum()` | Сложение | left + right |
| `double subtract()` | Вычитание | left − right |
| `double multiply()` | Умножение | left × right |
| `double divide()` | Деление | left / right |
| `double power()` | Возведение в степень | left ^ right |
| `double factorial()` | Факториал | left! |

### Исключения

| Исключение | Причина |
|---|---|
| `std::overflow_error` | Результат выходит за пределы допустимого диапазона |
| `std::runtime_error` | Деление на ноль |
| `std::invalid_argument` | Факториал отрицательного числа |

## Подключение через CMake (FetchContent)

```cmake
include(FetchContent)

FetchContent_Declare(
    integermath
    GIT_REPOSITORY https://github.com/AnastasiaVeselovskaya/CPP-IntergerMath.git
    GIT_TAG main
)

FetchContent_MakeAvailable(integermath)

target_link_libraries(your_target PRIVATE integermath)
```