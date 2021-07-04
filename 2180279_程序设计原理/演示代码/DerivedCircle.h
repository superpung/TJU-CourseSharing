#ifndef DERIVEDCIRCLE_H
#define DERIVEDCIRCLE_H
#include "GeometricObject.h"

class Circle: public GeometricObject
{
public:
  Circle();
  Circle(double);
  Circle(double radius, string color, bool filled);
  double getRadius();
  void setRadius(double);
  double getArea();
  double getPerimeter();
  double getDiameter();

private:
  double radius;
};  // Must place semicolon here

#endif
