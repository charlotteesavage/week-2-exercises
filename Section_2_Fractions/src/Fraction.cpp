#include "Fraction.h"

Fraction::Fraction(int a, int b)
{
    setValues(a,b);
}

Fraction::~Fraction() {};

void Fraction::setValues(int a, int b)
{
    numerator = a;
    denominator = b;
}

void Fraction::reciprocal()
{ 
    return setValues(denominator, numerator);
}

void Fraction::multiply(int a)
{
    return setValues(numerator*a, denominator);
}

double toDouble();

std::string toString();