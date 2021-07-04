#include "Rectangle.h"

// Construct a default retangle object
Rectangle::Rectangle()
{
  width = 1;
  height = 1;
}

// Construct a rectangle object with specified width and height
Rectangle::Rectangle(double width, double height)
{
  this->width = width;
  this->height = height;
}

// Return the width of this rectangle
double Rectangle::getWidth()
{
  return width;
}

// Set a new radius
void Rectangle::setWidth(double width)
{
  this->width = (width >= 0) ? width : 0;
}

// Return the height of this rectangle
double Rectangle::getHeight()
{
  return height;
}

// Set a new height
void Rectangle::setHeight(double height)
{
  this->height = (height >= 0) ? height : 0;
}

// Return the area of this rectangle
double Rectangle::getArea()
{
  return width * height;
}

// Return the perimeter of this rectangle
double Rectangle::getPerimeter()
{
  return 2 * (width + height);
}
