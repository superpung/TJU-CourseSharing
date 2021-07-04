#include "DerivedCircle.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main()
{
  GeometricObject shape;
  shape.setColor("red");
  shape.setFilled(true);
  cout << shape.toString() << endl;

  Circle circle(5);
  circle.setColor("black");
  circle.setFilled(false);
  cout << " Circle radius: " << circle.getRadius()
    << " area: " << circle.getArea()
    << " perimeter: " << circle.getPerimeter() << endl;
  cout << circle.toString() << endl;

  Rectangle rectangle(2, 3);
  rectangle.setColor("orange");
  rectangle.setFilled(true);
  cout << " Rectangle width: " << rectangle.getWidth()
    << " height: " << rectangle.getHeight()
    << " area: " << rectangle.getArea()
    << " perimeter: " << rectangle.getPerimeter() << endl;
  cout << rectangle.toString() << endl;

    system("pause");
  return 0;
}
