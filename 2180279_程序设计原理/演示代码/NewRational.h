#ifndef NEWRATIONL_H
#define NEWRATIONL_H
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

  // Define function operators for relational operators
  bool operator<(Rational &secondRational);
  bool operator<=(Rational &secondRational);
  bool operator>(Rational &secondRational);
  bool operator>=(Rational &secondRational);
  bool operator!=(Rational &secondRational);
  bool operator==(Rational &secondRational);

  // Define function operators for arithmetic operators
  Rational operator+(Rational &secondRational);
  Rational operator-(Rational &secondRational);
  Rational operator*(Rational &secondRational);
  Rational operator/(Rational &secondRational);

  // Define function operators for shorthand operators
  Rational operator+=(Rational &secondRational);
  Rational operator-=(Rational &secondRational);
  Rational operator*=(Rational &secondRational);
  Rational operator/=(Rational &secondRational);

  // Define function operator []
  long& operator[](const int &index);

  // Define function operators for prefix ++ and --
  Rational operator++();
  Rational operator--();

  // Define function operators for postfix ++ and --
  Rational operator++(int dummy);
  Rational operator--(int dummy);

  // Define function operators for unary + and -
  Rational operator+();
  Rational operator-();

  // Define the output and input operator
//  ostream &operator<<(ostream &stream, Rational &rational);
  friend istream &operator>>(istream &stream, Rational &rational);

  // Define function operator for conversion
  operator double();

private:
  long numerator;
  long denominator;
  static long gcd(long n, long d);
};

#endif
