#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(const string &courseName)
{
  numberOfStudents = 0;
  this->courseName = courseName;
}

string Course::getCourseName()
{
  return courseName;
}

void Course::addStudent(const string &student)
{
  if (numberOfStudents >= 100)
  {
    cout << "The maximum size of array exceeded" << endl;
    cout << "Program terminates now" << endl;
    exit(0);
  }

  students[numberOfStudents] = student;
  numberOfStudents++;
}

string * Course::getStudents()
{
  return students;
}

int Course::getNumberOfStudents()
{
  return numberOfStudents;
}
