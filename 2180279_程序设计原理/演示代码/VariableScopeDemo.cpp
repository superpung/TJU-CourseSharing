#include <iostream>
using namespace std;

void t1(); // function prototype
void t2(); // function prototype

int main()
{
  //cout<<y<<endl;
  t1();
  t2();
    system("pause");
  return 0;
}

int y; // Global variable, default to 0

void t1()
{
  int x = 1;
  cout << "x is " << x << endl;
  cout << "y is " << y << endl;
  x++;
  y++;
  {
      int y=22;
      cout<<::y<<endl;
      }
}

void t2()
{
  int x = 1;
  cout << "x is " << x << endl;
  cout << "y is " << y << endl;
}

