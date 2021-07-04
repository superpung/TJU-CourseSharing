#include "AbstractGeometricObject.h"
#include "TriangleException.h"
#include <cmath>

class Triangle: public GeometricObject
{
public:
  Triangle()
  {
    side1 = side2 = side3 = 1;
  }

  Triangle(double side1, double side2, double side3)
  {
    if (!isValid(side1, side2, side3))
      throw TriangleException(side1, side2, side3);

    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
  }

  double getSide1()
  {
    return side1;
  }

  double getSide2()
  {
    return side2;
  }

  double getSide3()
  {
    return side3;
  }

  void setSide1(double side1)
  {
    if (!isValid(side1, side2, side3))
      throw TriangleException(side1, side2, side3);

    this->side1 = side1;
  }

  void setSide2(double side2)
  {
    if (!isValid(side1, side2, side3))
      throw TriangleException(side1, side2, side3);

    this->side2 = side2;
  }

  void setSide3(double side3)
  {
    if (!isValid(side1, side2, side3))
      throw TriangleException(side1, side2, side3);

    this->side3 = side3;
  }

  double getPerimeter()
  {
    return side1 + side2 + side3;
  }

  double getArea()
  {
    double s = getPerimeter() / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
  }

private:
  double side1, side2, side3;

  bool isValid(double side1, double side2, double side3)
  {
    return (side1 < side2 + side3) && (side2 < side1 + side3) &&
      (side3 < side1 + side2);
  }
};
