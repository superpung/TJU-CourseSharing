#include "Student.h"

// No-arg constructor
Student::Student()
{
}

// Construct a Student object with specified data
Student::Student
  (string firstName, char mi, string lastName, int score)
{
  setFirstName(firstName);
  setMi(mi);
  setLastName(lastName);
  setScore(score);
}

void Student::setFirstName(string s)
{
  firstName = s;
}

void Student::setMi(char mi)
{
  this->mi = mi;
}

void Student::setLastName(string s)
{
  lastName = s; 
}

void Student::setScore(int score)
{
  this->score = score;
}

string Student::getFirstName()
{
  return firstName;
}

char Student::getMi()
{
  return mi;
}

string Student::getLastName()
{
  return lastName;
}

int Student::getScore()
{
  return score;
}
