#include "DerivedCircle2.h"
#include "Rectangle2.h"
#include <iostream>
using namespace std;

int main()
{
  try
  {
    Rectangle r(3, 4);
    Circle & c = dynamic_cast<Circle&>(r);
  }
  catch (bad_cast &e)
  {
    cout << "Exception: " << e.what() << endl;
  }
  system("pause");
  return 0; 
}
