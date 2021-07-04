#include <iostream>
#include "NewTriangle.h"
using namespace std;

int main()
{
  try
  {
    cout << "Enter three sides: ";
    double side1, side2, side3;
    cin >> side1 >> side2 >> side3;
    Triangle triangle(side1, side2, side3);
    cout << "Perimeter is " << triangle.getPerimeter() << endl;
    cout << "Area is " << triangle.getArea() << endl;
  }
  catch (NonPositiveSideException &ex)
  {
    cout << ex.what();
    cout << " the side is " << ex.getSide() << endl;
  }
  catch (TriangleException &ex)
  {
    cout << ex.what();
    cout << " three sides are " << ex.getSide1() << " "
      << ex.getSide2() << " " << ex.getSide3() << endl;
  }
}
