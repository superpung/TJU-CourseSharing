#include <iostream>
#include "Rational.h"
using namespace std;

Rational::Rational()
{
  numerator = 0;
  denominator = 1;
}

Rational::Rational(long numerator, long denominator)
{
  long factor = gcd(numerator, denominator);
  this->numerator = ((denominator > 0) ? 1 : -1) * numerator / factor;
  this->denominator = abs(denominator) / factor;
}

long Rational::getNumerator()
{
  return numerator;
}

long Rational::getDenominator()
{
  return denominator;
}

/** Find GCD of two numbers */
long Rational::gcd(long n, long d) {
  long n1 = abs(n);
  long n2 = abs(d);
  int gcd = 1;

  for (int k = 1; k <= n1 && k <= n2; k++)
  {
    if (n1 % k == 0 && n2 % k == 0)
      gcd = k;
  }

  return gcd;
}

Rational Rational::add(Rational &secondRational)
{
  long n = numerator * secondRational.getDenominator() +
    denominator * secondRational.getNumerator();
  long d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::subtract(Rational &secondRational)
{
  long n = numerator * secondRational.getDenominator()
    - denominator * secondRational.getNumerator();
  long d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::multiply(Rational &secondRational)
{
  long n = numerator * secondRational.getNumerator();
  long d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::divide(Rational &secondRational)
{
  long n = numerator * secondRational.getDenominator();
  long d = denominator * secondRational.numerator;
  return Rational(n, d);
}

int Rational::compareTo(Rational &secondRational)
{
  Rational temp = this->subtract(secondRational);
  if (temp.getNumerator() < 0)
    return -1;
  else if (temp.getNumerator() == 0)
    return 0;
  else
    return 1;
}

bool Rational::equals(Rational &secondRational)
{
  if (this->compareTo(secondRational) == 0)
    return true;
  else
    return false;
}

int Rational::intValue()
{
  return getNumerator() / getDenominator();
}

double Rational::doubleValue()
{
  return 1.0 * getNumerator() / getDenominator();
}

string Rational::toString()
{
  char s1[20], s2[20];
  itoa(numerator, s1, 10); // Convert int to string s1
  itoa(denominator, s2, 10); // Convert int to string s2

  if (denominator == 1)
    return string(s1);
  else
    return string(strcat(strcat(s1, "/"), s2));
}
