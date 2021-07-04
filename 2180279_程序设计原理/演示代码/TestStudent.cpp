#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
  Student student(111223333, 1970, 5, 3);
  BirthDate *pDate = student.getBirthDate();
  pDate -> setYear(2010);
  cout << student.getBirthDate() -> getYear();
    system("pause");
  return 0;
}
