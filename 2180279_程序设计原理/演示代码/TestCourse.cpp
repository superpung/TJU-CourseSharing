#include <iostream>
#include "Course.h"
using namespace std;

int main()
{
  Course course1("Data Structures");
  Course course2("Database Systems");

  course1.addStudent("Peter Jones");
  course1.addStudent("Brian Smith");
  course1.addStudent("Anne Kennedy");

  course2.addStudent("Peter Jones");
  course2.addStudent("Steve Smith");

  cout << "Number of students in course1: " <<
    course1.getNumberOfStudents() << "\n";
  string * students = course1.getStudents();
  for (int i = 0; i < course1.getNumberOfStudents(); i++)
    cout << students[i] << ", ";

  cout << "\nNumber of students in course2: "
    << course2.getNumberOfStudents() << "\n";
  students = course2.getStudents();
  for (int i = 0; i < course2.getNumberOfStudents(); i++)
    cout << students[i] << ", ";

    system("pause");
  return 0;
}
