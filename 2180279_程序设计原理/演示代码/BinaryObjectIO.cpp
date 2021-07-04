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
  binaryio.open("object.dat", ios::out | ios::binary);

  Student student1("John", 'T', "Smith", 90);
  Student student2("Eric", 'K', "Jones", 85);

  binaryio.write(reinterpret_cast<char *>
    (&student1), sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student2), sizeof(Student));

  binaryio.close();

  // Read student back from the file
  binaryio.open("object.dat", ios::in | ios::binary);

  Student studentNew;

  binaryio.read(reinterpret_cast<char *>
    (& studentNew), sizeof(Student));

  displayStudent(studentNew);

  binaryio.read(reinterpret_cast<char *>
    (& studentNew), sizeof(Student));

  displayStudent(studentNew);

  binaryio.close();

    system("pause");
  return 0;
}
