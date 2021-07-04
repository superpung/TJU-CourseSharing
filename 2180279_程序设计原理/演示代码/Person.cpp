#include "Person.h"

Person::Person(int id, int year, int month, int day)
{
  this -> id = id;
  birthDate = new Date(year, month, day);
}

int Person::getId()
{
  return id;
}

Date * Person::getBirthDate()
{
  return birthDate; // Return the pointer of the object
}
