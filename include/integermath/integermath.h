#pragma once
#include <cfloat>
#include <climits>
#include <cstdint>
#include <stdexcept>

namespace integermath
{

template <typename T>
class CalculationModule
{
public:
    void SetLeftNumber(T number) {
        left_number_ = number;
    }

    void SetRightNumber(T number) {
        right_number_ = number;
    }

    T getLeftNumber() {
        return left_number_;
    }

    T getRightNumber() {
        return right_number_;
    }

    inline double power() 
    {
        if (right_number_ == 0)
        {
            return 1;
        }

        if (left_number_ == 0) 
        {
            return 0;
        }

        if (left_number_ == 1)
        {
            return 1;
        }

        if (left_number_ == -1)
        {
            return (right_number_ % 2 == 0) ? 1 : -1;
        }

        double result = static_cast<double>(left_number_);
        int64_t const absPower = right_number_ > 0 ? right_number_ : -1 * right_number_;
        double const absBase =
            (left_number_ > 0) ? static_cast<double>(left_number_) : static_cast<double>(-left_number_);

        for (int64_t i = 1; i < absPower; ++i)
        {
            double const absResult = (result > 0) ? result : -result;

            if (absResult > DBL_MAX / absBase)
            {
                throw std::overflow_error("Calculation resulted in type overflow\n");
            }

            result *= static_cast<double>(left_number_);
        }

        if (right_number_ < 0)
        {
            result = 1.0 / result;
        }

        return result;
    }

    inline double factorial()
    {
        if (left_number_ < 0)
        {
            throw std::invalid_argument("Negative number passed for factorial calculation\n");
        }

        if (left_number_ == 0)
        {
            return 1.0;
        }

        return factorialRec(static_cast<double>(left_number_));
    }

    inline double sum()
    {
        if ((right_number_ > 0 && left_number_ > LONG_MAX - right_number_) ||
            (right_number_ < 0 && left_number_ < LONG_MIN - right_number_))
        {
            throw std::overflow_error("Calculation resulted in type overflow\n");
        }
        double result = static_cast<double>(left_number_) + static_cast<double>(right_number_);
        return result;
    }

    inline double subtract()
    {
        if ((right_number_ > 0 && left_number_ < LONG_MIN + right_number_) ||
            (right_number_ <  0 && left_number_ > LONG_MAX + right_number_))
        {
            throw std::overflow_error("Calculation resulted in type overflow\n");
        }
        double result = static_cast<double>(left_number_) - static_cast<double>(right_number_);
        return result;
    }

    inline double divide()
    {
        if (right_number_ == 0)
        {
            throw std::runtime_error("Division by zero");
        }
        double result = static_cast<double>(left_number_) / static_cast<double>(right_number_);
        return result;
    }

    
    inline double multiply()
    {
        if (left_number_ == 0 || right_number_ == 0)
        {
            return 0.0;
        }

        int64_t const absA = (left_number_ > 0) ? left_number_ : -left_number_;
        int64_t const absB = (right_number_ > 0) ? right_number_ : -right_number_;

        if (absA > LONG_MAX / absB)
        {
            throw std::overflow_error("Calculation resulted in type overflow\n");
        }

        double result = static_cast<double>(left_number_) * static_cast<double>(right_number_);
        return result;
    }

private:
    double factorialRec (double number)
    {
        if (number <= 1)
        {
            return 1;
        }

        double previous = factorialRec(number - 1);

        if (previous > LONG_MAX / number)
        {
            throw std::overflow_error("Calculation resulted in type overflow\n");
        }

        return previous * number;
    };


    T left_number_ = T{};
    T right_number_ = T{};
};

} // namespace integermath
