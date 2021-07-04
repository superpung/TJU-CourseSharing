#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

void displayStudent(Student student)
{
  cout << student.getFirstName() << " ";
  cout << student.getMi() << " ";
  cout << student.getLastName() << " ";
  cout << student.getScore() << endl;
}

int main()
{
  fstream binaryio; // Create stream object

  // Open file for input and output
  binaryio.open("object1.dat", ios::in | ios::out | ios::binary);

  Student student1;
  binaryio.seekg(2 * sizeof(Student));
  binaryio.read(reinterpret_cast<char *>
    (&student1), sizeof(Student));
  displayStudent(student1);

  student1.setLastName("Peterson");
  binaryio.seekp(2 * sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student1), sizeof(Student));

  Student student2;
  binaryio.seekg(2 * sizeof(Student));
  binaryio.read(reinterpret_cast<char *>
    (&student2), sizeof(Student));
  displayStudent(student2);

  binaryio.close();

    system("pause");
  return 0;
}
