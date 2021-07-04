#include <iostream>
using namespace std;

class Person
{
public:
  Person()
  {
    cout << "Person's constructor is invoked" << endl;
  }

  ~Person()
  {
    cout << "Person's destructor is invoked" << endl;
  }
};

class Employee: public Person
{
public:
  Employee()
  {
    cout << "Employee's constructor is invoked" << endl;
  }

  ~Employee()
  {
    cout << "Employee's destructor is invoked" << endl;
  }
};

class Faculty: public Employee
{
public:
  Faculty()
  {
    cout << "Faculty's constructor is invoked" << endl;
  }

  ~Faculty()
  {
    cout << "Faculty's destructor is invoked" << endl;
  }
};

int main()
{
  Faculty faculty;
  system("pause");
  return 0; 
}
