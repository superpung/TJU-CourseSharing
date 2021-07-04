#include <iostream>
using namespace std;

class B
{
public:
  int i;

protected:
  int j;

private:
  int k;
};

class A: public B
{
public:
  void display()
  {
    cout << i << endl; // Fine, cannot access it
    cout << j << endl; // Fine, cannot access it
    cout << k << endl; // Wrong, cannot access it
  }
};

int main()
{
  A a;
  cout << a.i << endl; // Fine, cannot access it
  cout << a.j << endl; // Wrong, cannot access it
  cout << a.k << endl; // Wrong, cannot access it
    system("pause");
  return 0;
}
