#include "DerivedCircle.h"

// Construct a default circle object
Circle::Circle()
{
  radius = 1;
}

// Construct a circle object with specified radius
Circle::Circle(double radius)
{
  this->radius = radius;
}

// Return the radius of this circle
double Circle::getRadius()
{
  return radius;
}

// Set a new radius
void Circle::setRadius(double radius)
{
  this->radius = (radius >= 0) ? radius : 0;
}

// Return the area of this circle
double Circle::getArea()
{
  return radius * radius * 3.14159;
}

// Return the perimeter of this circle
double Circle::getPerimeter()
{
  return 2 * radius * 3.14159;
}

// Return the diameter of this circle
double Circle::getDiameter()
{
  return 2 * radius;
}
