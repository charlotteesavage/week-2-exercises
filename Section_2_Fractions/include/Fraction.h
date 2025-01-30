#pragma once
#include <string>

class Fraction
{
    public:
    Fraction(int a, int b);
    ~Fraction();
    void setValues(int a, int b);
    void reciprocal();
    void multiply(int a);
    double toDouble();
    std::string toString();

    private:
    int numerator;
    int denominator;
};
