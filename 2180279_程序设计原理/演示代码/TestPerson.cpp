#include <iostream>
#include "Person.h"
using namespace std;

int main()
{
  Person person(111223333, 1970, 5, 3);
  cout << "birth year before the change is " <<
    person.getBirthDate() -> getYear() << endl;
  Date *pDate = person.getBirthDate();
  pDate -> setYear(2010);
  cout << "birth year after the change is " <<
    person.getBirthDate() -> getYear() << endl;
    system("pause");
  return 0;
}
