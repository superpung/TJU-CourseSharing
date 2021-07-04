#include <iostream>
#include "Date2.h"
using namespace std;

class AccessDate
{
public:
  static void p()
  {
    Date birthDate;
    birthDate.year = 2000;
    cout << birthDate.year;
  }
};

int main()
{
  AccessDate::p();
    system("pause");
  return 0;
}
