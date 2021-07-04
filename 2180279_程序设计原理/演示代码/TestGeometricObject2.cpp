#include "DerivedCircle2.h"
#include "Rectangle2.h"
#include <iostream>
using namespace std;

// A function for comparing the areas of two geometric objects
bool equalArea(GeometricObject &object1,
  GeometricObject &object2)
{
  return object1.getArea() == object2.getArea();
}

// A function for displaying a geometric object
void displayGeometricObject(GeometricObject &object)
{
  cout << "The area is " << object.getArea() << endl;
  cout << "The perimeter is " << object.getPerimeter() << endl;
}

int main()
{
  Circle circle(5);
  Rectangle rectangle(5, 3);

  cout << "Circle info: " << endl;
  displayGeometricObject(circle);

  cout << "\nRectangle info: " << endl;
  displayGeometricObject(rectangle);

  cout << "\nThe two objects have the same area? " <<
    (equalArea(circle, rectangle) ? "Yes" : "No") << endl;

    system("pause");
  return 0;
}
