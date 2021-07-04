#include <iostream>
#include <iso646.h>
using namespace std;

namespace namespace1
{
  double x = 1;

  void p()
  {
    cout << "from namespace1" << endl;
  }
}

namespace namespace2
{
  double x = 2;

  void p()
  {
    cout << "from namespace2" << endl;
  }
}

using namespace namespace1;

int main()
{
  cout << namespace1::x << endl;
  cout << namespace2::x << endl;

  p();
  namespace2::p();

    system("pause");
  return 0;
}

