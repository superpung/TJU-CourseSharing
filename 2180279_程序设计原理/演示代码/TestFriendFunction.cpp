#include <iostream>
using namespace std;

class Date
{
  friend void p();

private:
  int year;
  int month;
  int day;
};

void p()
{
  Date date;
  date.year = 2000;
  cout << date.year;
}

int main()
{
  p();
    system("pause");
  return 0;
}
