#ifndef RATIONL_H
#define RATIONL_H
#include <string>
using namespace std;

class Rational
{
public:
  Rational();
  Rational(long numerator, long denominator);
  long getNumerator();
  long getDenominator();
  Rational add(Rational &secondRational);
  Rational subtract(Rational &secondRational);
  Rational multiply(Rational &secondRational);
  Rational divide(Rational &secondRational);
  int compareTo(Rational &secondRational);
  bool equals(Rational &secondRational);
  int intValue();
  double doubleValue();
  string toString();

private:
  long numerator;
  long denominator;
  static long gcd(long n, long d);
};

#endif
