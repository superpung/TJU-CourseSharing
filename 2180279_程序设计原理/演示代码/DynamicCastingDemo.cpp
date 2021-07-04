#include "DerivedCircle2.h"
#include "Rectangle2.h"
#include <iostream>
using namespace std;

// A function for displaying a geometric object
void displayGeometricObject(GeometricObject &object)
{
  cout << "The area is " << object.getArea() << endl;
  cout << "The perimeter is " << object.getPerimeter() << endl;

  GeometricObject *p = &object;
  Circle *p1 = dynamic_cast<Circle*>(p);
  Rectangle *p2 = dynamic_cast<Rectangle*>(p);

  if (p1 != 0)
  {
    cout << "The radius is " << p1->getRadius() << endl;
    cout << "The diameter is " << p1->getDiameter() << endl;
  }

  if (p2 != 0)
  {
    cout << "The width is " << p2->getWidth() << endl;
    cout << "The height is " << p2->getHeight() << endl;
  }
}

int main()
{
  Circle circle(5);
  Rectangle rectangle(5, 3);

  cout << "Circle info: " << endl;
  displayGeometricObject(circle);

  cout << "\nRectangle info: " << endl;
  displayGeometricObject(rectangle);

    system("pause");
  return 0;
}
