#include <iostream>
#include "MyCalendar.h"
using namespace std;

int main()
{
  // Prompt the user to enter year
  cout << "Enter full year (e.g., 2001): ";
  int year;
  cin >> year;

  // Prompt the user to enter month
  cout << "Enter month in number between 1 and 12: ";
  int month;
  cin >> month;

  // Print calendar for the month of the year
  MyCalendar calendar(year, month);

  calendar.printMonth();

  calendar.setYear(2007);
  calendar.setMonth(1);

  cout << "\n\nThe first day of 2007 is " << calendar.getStartDay() << endl;

    system("pause");
  return 0;
}
