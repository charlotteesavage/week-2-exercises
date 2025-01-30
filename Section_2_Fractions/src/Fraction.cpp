#include "Fraction.h"
#include <string> 
#include <iostream>

int gcd(int a, int b) {
    if (b == 0) return abs(a);
    return gcd(b, a % b);
}

Fraction::Fraction(int a, int b)
{
    setValues(a,b);
}

Fraction::~Fraction() {};

void Fraction::setValues(int a, int b)
{   

if (a==0)
{numerator =a; denominator = 1;
return;}
if (b == 0) 
{ 
numerator =a; 
denominator = 1;
std::cerr << "Warning: Division by zero attempted. Setting denominator to 1." << std::endl;
return;
    } 
else
{
    int common = gcd(a,b);
    numerator = a/ common;
    denominator = b/ common;
}
}

void Fraction::reciprocal()
{ 
    if (numerator == 0) {
        std::cerr << "Warning: Cannot take reciprocal of zero." << std::endl;
        return;
    }
    setValues(denominator, numerator);
}

void Fraction::multiply(int a)
{
    setValues(numerator*a, denominator);
}

double Fraction::toDouble()
{
    return static_cast<double>(numerator) / denominator;
}

std::string Fraction::toString()
{
if (numerator == 0)
{return "0";}
else
{std::string s = std::to_string(numerator) + "/" + std::to_string(denominator);
return s;}
}