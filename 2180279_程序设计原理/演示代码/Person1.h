#include "Date1.h"

class Person
{
public:
  Person(int id, int year, int month, int day);
  Person(Person &);
  ~Person();
  int getId();
  Date * getBirthDate(); // Return the pointer of the object

private:
  int id;
  Date *birthDate; // The pointer of the object
};
