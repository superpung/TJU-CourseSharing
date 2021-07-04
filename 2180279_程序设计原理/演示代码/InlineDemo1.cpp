#include <iostream>
using namespace std;

inline void f(int month, int year) {
  cout << "month is " << month << endl;
  cout << "year is " << year << endl;
}

int main()
{
  int month = 10, year = 2008;
  f(month, year);
    system("pause");
  return 0;
}
