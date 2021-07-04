#ifndef CIRCLE6_H
#define CIRCLE6_H

class Circle
{
public:
  Circle();
  Circle(double);
  ~Circle();
  double getArea();
  double getRadius();
  void setRadius(double);
  static int getNumberOfObjects();

private:
  double radius;
  static int numberOfObjects;
};

#endif
