# IntegerMath

Header-only библиотека для выполнения арифметических операций с проверкой переполнения.
Все операции возвращают статус выполнения и записывают результат в переменную типа `double`.
Для успешной сборки необходим компилятор с поддержкой C++17 или новее.

## Пример использования

```cpp
#include <integermath/integermath.h>
#include <cstdio>

int main() {
    double result;
    int status;
    
    // Сложение
    status = integermath::sum(100, 200, result);
    if (status == 0) printf("100 + 200 = %.0f\n", result);
    
    // Умножение с проверкой переполнения
    status = integermath::multiply(1000000, 3000000, result);
    if (status == -1) printf("Переполнение!\n");
    
    // Деление
    integermath::divide(10, 3, result);
    printf("10 / 3 = %f\n", result);
    
    // Возведение в степень
    integermath::power(2, 10, result);
    printf("2^10 = %.0f\n", result);
    
    // Факториал
    integermath::factorial(5, result);
    printf("5! = %.0f\n", result);
    
    return 0;
}
```
