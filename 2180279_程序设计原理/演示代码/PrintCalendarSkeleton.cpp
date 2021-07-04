#include <iostream>
#include <iomanip>
using namespace std;

void printMonth(int year, int month);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month);
int getStartDay(int year, int month);
int getTotalNumberOfDays(int year, int month);
int getNumberOfDaysInMonth(int year, int month);
bool isLeapYear(int year);

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
  printMonth(year, month);

    system("pause");
  return 0;
}

void printMonth(int year, int month)
{
  cout << month << "  " << year << endl;
}
