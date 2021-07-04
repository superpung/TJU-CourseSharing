#include <iostream>
#include "Circle5.h"
using namespace std;

int main()
{
  cout << "Number of circle objects created: "
    << Circle::getNumberOfObjects() << endl;

  Circle circle1;
  cout << "The area of the circle of radius "
    << circle1.getRadius() << " is " << circle1.getArea() << endl;
  cout << "Number of circle objects created: "
    << Circle::getNumberOfObjects() << endl;

  Circle circle2(5.0);
  cout << "The area of the circle of radius "
    << circle2.getRadius() << " is " << circle2.getArea() << endl;
  cout << "Number of circle objects created: "
      << Circle::getNumberOfObjects() << endl;

  circle1.setRadius(3.3);
  cout << "The area of the circle of radius "
    << circle1.getRadius() << " is " << circle1.getArea() << endl;

  cout << "circle1.getNumberOfObjects() returns "
    << circle1.getNumberOfObjects() << endl;
  cout << "circle2.getNumberOfObjects() returns "
    << circle2.getNumberOfObjects() << endl;

    system("pause");
  return 0;
}
