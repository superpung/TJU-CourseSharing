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
  binaryio.open("object1.dat", ios::out | ios::binary);

  Student student1("Student1", 'T', "Smith", 90);
  Student student2("Student2", 'T', "Smith", 90);
  Student student3("Student3", 'T', "Smith", 90);
  Student student4("Student4", 'T', "Smith", 90);
  Student student5("Student5", 'T', "Smith", 90);
  Student student6("Student6", 'T', "Smith", 90);
  Student student7("Student7", 'T', "Smith", 90);
  Student student8("Student8", 'T', "Smith", 90);
  Student student9("Student9", 'T', "Smith", 90);
  Student student10("Student10", 'T', "Smith", 90);

  binaryio.write(reinterpret_cast<char *>
    (&student1), sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student2), sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student3), sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student4), sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student5), sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student6), sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student7), sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student8), sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student9), sizeof(Student));
  binaryio.write(reinterpret_cast<char *>
    (&student10), sizeof(Student));

  binaryio.close();

  // Read student back from the file
  binaryio.open("object1.dat", ios::in | ios::binary);

  Student studentNew;

  binaryio.seekg(2 * sizeof(Student));

  cout << "Current position is " << binaryio.tellg() << endl;

  binaryio.read(reinterpret_cast<char *>
    (& studentNew), sizeof(Student));

  displayStudent(studentNew);

  cout << "Current position is " << binaryio.tellg() << endl;

  binaryio.close();

    system("pause");
  return 0;
}
