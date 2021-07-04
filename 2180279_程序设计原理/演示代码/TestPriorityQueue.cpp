#include <iostream>
#include "PriorityQueue.h"
using namespace std;

class Patient
{
public:
  Patient(string name, int priority)
  {
    this->name = name;
    this->priority = priority;
  }

  bool operator<(Patient &secondPatient)
  {
    return (this->priority < secondPatient.priority);
  }

  bool operator>(Patient &secondPatient)
  {
    return (this->priority > secondPatient.priority);
  }

  string getName()
  {
    return name;
  }

  int getPriority()
  {
    return priority;
  }

private:
  string name;
  int priority;
};

int main()
{
  // Queue of patients
  PriorityQueue<Patient> patientQueue;
  patientQueue.enqueue(Patient("John", 2));
  patientQueue.enqueue(Patient("Jim", 1));
  patientQueue.enqueue(Patient("Tim", 5));
  patientQueue.enqueue(Patient("Cindy", 7));

  while (patientQueue.getSize() > 0)
  {
    Patient element = patientQueue.dequeue();
    cout << element.getName() << "(priority: " <<
      element.getPriority() << ") ";
  }

    system("pause");
  return 0;
}
