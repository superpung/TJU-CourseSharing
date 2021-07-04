#include <iostream>
#include "Person.h"
using namespace std;

void displayPerson(Person &person1, Person &person2)
{
  cout << "\tperson1 id: " << person1.getId() << endl;
  cout << "\tperson1 birth year: " <<
    person1.getBirthDate() -> getYear() << endl;
  cout << "\tperson2 id: " << person2.getId() << endl;
  cout << "\tperson2 birth year: " <<
    person2.getBirthDate() -> getYear() << endl;
}

int main()
{
  Person person1(111, 1970, 5, 3);
  Person person2(222, 2000, 11, 8);

  cout << "After creating person1 and person2" << endl;
  displayPerson(person1, person2);

  person1 = person2; // Copy person2 to person1

  cout << "\nAfter copying person2 to person1" << endl;
  displayPerson(person1, person2);

  person2.getBirthDate() -> setYear(1963);

  cout << "\nAfter modifying person2's birthDate" << endl;
  displayPerson(person1, person2);

  cout << "\n" << (person1.getBirthDate() == person2.getBirthDate());
    system("pause");
  return 0;
}
