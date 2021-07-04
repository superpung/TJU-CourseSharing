#include <iostream>
using namespace std;

class C
{
public:
  string toString()
  {
    return "class C";
  }
};

class B: public C
{
  string toString()
  {
    return "class B";
  }
};

class A: public B
{
  string toString()
  {
    return "class A";
  }
};

void displayObject(C x)
{
  cout << x.toString().data() << endl;
}

int main()
{
  displayObject(A());
  displayObject(B());
  displayObject(C());
    system("pause");
  return 0;
}
