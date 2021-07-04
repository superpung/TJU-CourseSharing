#include <iostream>
#include "Triangle.h"
using namespace std;

int main()
{
  try
  {
    Triangle triangle;
    cout << "Perimeter is " << triangle.getPerimeter() << endl;
    cout << "Area is " << triangle.getArea() << endl;

    triangle.setSide3(4);
    cout << "Perimeter is " << triangle.getPerimeter() << endl;
    cout << "Area is " << triangle.getArea() << endl;
  }
  catch (TriangleException &ex)
  {
    cout << ex.what();
    cout << " three sides are " << ex.getSide1() << " "
      << ex.getSide2() << " " << ex.getSide3() << endl;
  }

    system("pause");
  return 0;
}
