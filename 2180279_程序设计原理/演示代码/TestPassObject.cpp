#include <iostream>
#include "Circle2.h"
using namespace std;

void printAreas(Circle * c, int times)
{
  cout << "Radius \t\tArea" << endl;
  while (times >= 1)
  {
    cout << c->getRadius() << "\t\t" << c->getArea() << endl;
    c->setRadius(c->getRadius() + 1);
    times--;
  }
}

int main()
{
  // Create a Circle object with radius 1
  Circle myCircle(1);

  // Print areas for radius 1, 2, 3, 4, and 5.
  int n = 5;
  printAreas(&myCircle, n);

  // See myCircle.radius and times
  cout << "\n" << "Radius is " << myCircle.getRadius() << endl;
  cout << "n is " << n << endl;
    system("pause");
  return 0;
}
