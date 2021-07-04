#include <iostream>
#include "Circle6.h"
using namespace std;

int main()
{
  Circle *pCircle1 = new Circle();
  Circle *pCircle2 = new Circle();
  Circle *pCircle3 = new Circle();

  cout << "Number of circle objects created: "
    << Circle::getNumberOfObjects() << endl;

  delete pCircle1;

  cout << "Number of circle objects created: "
    << Circle::getNumberOfObjects() << endl;

    system("pause");
  return 0;
}
