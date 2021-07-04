#include <iostream>
using namespace std;

class B1
{
public:
  void p1()
  {
    cout << "from B1" << endl;
  }
};

class B2
{
  public:
    void p2()
    {
      cout << "from B2" << endl;
    }
};

class A: public B1, public B2
{
};

int main()
{
  A a;
  a.p1();
  a.p2();
    system("pause");
  return 0;
}
