#include <iostream>
#include "Circle6.h"
using namespace std;

int main()
{
  Circle circle1(10);
  Circle circle2(20);

  circle1 = circle2;

  cout << "circle1.getRadius() returns "
    << circle1.getRadius() << endl;
  cout << "circle2.getRadius() returns "
    << circle2.getRadius() << endl;

  circle1.setRadius(10.5);
  circle2.setRadius(20.5);

 cout << "circle1.getRadius() returns "
   << circle1.getRadius() << endl;
 cout << "circle2.getRadius() returns "
   << circle2.getRadius() << endl;

    system("pause");
  return 0;
}
