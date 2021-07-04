#include "Date.h"

class Person
{
public:
  Person(int id, int year, int month, int day);
  int getId();
  Date* getBirthDate(); // Return the pointer of the object

private:
  int id;
  Date* birthDate; // The pointer of the object
};
