#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
public:
  Course(const string &courseName);
  string getCourseName();
  void addStudent(const string &student);
  string * getStudents();
  int getNumberOfStudents();

private:
  string courseName;
  string students[100];
  int numberOfStudents;
};

#endif
