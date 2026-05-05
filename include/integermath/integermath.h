#pragma once
#include <cfloat>
#include <climits>
#include <cstdint>

namespace integermath
{

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
inline int power(int64_t base, int64_t power, double& result)
{
    if (power == 0)
    {
        result = 1;
        return 0;
    }

    if (base == 0)
    {
        result = 0;
        return 0;
    }

    if (base == 1)
    {
        result = 1;
        return 0;
    }

    if (base == -1)
    {
        result = (power % 2 == 0) ? 1 : -1;
        return 0;
    }

    result = static_cast<double>(base);
    int64_t const absPower = power > 0 ? power : -1 * power;
    double const absBase =
        (base > 0) ? static_cast<double>(base) : static_cast<double>(-base);

    for (int64_t i = 1; i < absPower; ++i)
    {
        double const absResult = (result > 0) ? result : -result;

        if (absResult > DBL_MAX / absBase)
        {
            return -1;
        }

        result *= static_cast<double>(base);
    }

    if (power < 0)
    {
        result = 1.0 / result;
    }

    return 0;
}

inline int factorial(int64_t base, double& result)
{
    // NOLINTNEXTLINE(misc-no-recursion)
    auto factorialRec = [](auto&& self, int64_t base, int& status) -> int64_t {
        if (base <= 1)
        {
            return base;
        }

        int64_t const previous = self(self, base - 1, status);
        if (status == -1)
        {
            return 0;
        }

        if (previous > LONG_MAX / base)
        {
            status = -1;
            return 0;
        }

        return previous * base;
    };

    if (base < 0)
    {
        return -1;
    }

    if (base == 0)
    {
        result = 1;
        return 0;
    }

    int status = 0;
    result = static_cast<double>(factorialRec(factorialRec, base, status));
    return status;
}

inline int sum(int64_t leftNumber, int64_t rightNumber, double& result)
{
    if ((rightNumber > 0 && leftNumber > LONG_MAX - rightNumber) ||
        (rightNumber < 0 && leftNumber < LONG_MIN - rightNumber))
    {
        return -1;
    }
    result = static_cast<double>(leftNumber) + static_cast<double>(rightNumber);
    return 0;
}

inline int subtract(int64_t leftNumber, int64_t rightNumber, double& result)
{
    if ((rightNumber < 0 && leftNumber < LONG_MIN + rightNumber) ||
        (rightNumber > 0 && leftNumber > LONG_MAX + rightNumber))
    {
        return -1;
    }
    result = static_cast<double>(leftNumber) - static_cast<double>(rightNumber);
    return 0;
}

inline int divide(int64_t leftNumber, int64_t rightNumber, double& result)
{
    if (rightNumber == 0)
    {
        return -1;
    }
    result = static_cast<double>(leftNumber) / static_cast<double>(rightNumber);
    return 0;
}

inline int multiply(int64_t leftNumber, int64_t rightNumber, double& result)
{
    if (leftNumber == 0 || rightNumber == 0)
    {
        result = 0.0;
        return 0;
    }

    int64_t const absA = (leftNumber > 0) ? leftNumber : -leftNumber;
    int64_t const absB = (rightNumber > 0) ? rightNumber : -rightNumber;

    if (absA > LONG_MAX / absB)
    {
        return -1;
    }

    result = static_cast<double>(leftNumber) * static_cast<double>(rightNumber);
    return 0;
}

} // namespace integermath

