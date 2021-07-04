#include <iostream>
using namespace std;

class Foo
{
  public:
  int x; // data field
  int y; // data field

  Foo()
  {
    x = 10;
    y = 10;
  }

  void p()
  {
    int x = 20; // local variable
    cout << "x is " << this->x << endl;
    cout << "y is " << y << endl;
  }
};

int main()
{
  Foo foo;
  foo.p();

    system("pause");
  return 0;
}
