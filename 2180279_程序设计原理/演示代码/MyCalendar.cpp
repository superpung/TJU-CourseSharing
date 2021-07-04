#include "MyCalendar.h"
#include <iostream>
#include <iomanip>
using namespace std;

MyCalendar::MyCalendar(int year, int month)
{
  this->year = year;
  this->month = month;
}

int MyCalendar::getYear()
{
  return year;
}

void MyCalendar::setMonth(int newMonth)
{
  month = newMonth;
}

int MyCalendar::getMonth()
{
  return month;
}

void MyCalendar::setYear(int newYear)
{
  year = newYear;
}

// Print the calendar for a month in a year
void MyCalendar::printMonth()
{
  // Print the headings of the calendar
  printMonthTitle();

  // Print the body of the calendar
  printMonthBody();
}

// Print the month title, e.g., May, 1999
void MyCalendar::printMonthTitle()
{
  printMonthName();
  cout << " " << year << endl;
  cout << "-----------------------------" << endl;
  cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
}

// Get the English name for the month
void MyCalendar::printMonthName()
{
  cout << setw(16);
  switch (month)
  {
    case 1:
      cout << "January";
      break;
    case 2:
      cout << "February";
      break;
    case 3:
      cout << "March";
      break;
    case 4:
      cout << "April";
      break;
    case 5:
      cout << "May";
      break;
    case 6:
      cout << "June";
      break;
    case 7:
      cout << "July";
      break;
    case 8:
      cout << "August";
      break;
    case 9:
      cout << "September";
      break;
    case 10:
      cout << "October";
      break;
    case 11:
      cout << "November";
      break;
    case 12:
      cout << setw(16) << "December";
  }
}

// Print month body
void MyCalendar::printMonthBody()
{
  // Get start day of the week for the first date in the month
  int startDay = getStartDay();

  // Get number of days in the month
  int numberOfDaysInMonth = getNumberOfDaysInMonth(year, month);

  // Pad space before the first day of the month
  int i = 0;
  for (i = 0; i < startDay; i++)
    cout << "    ";

  for (i = 1; i <= numberOfDaysInMonth; i++)
  {
     cout << setw(4) << i;

    if ((i + startDay) % 7 == 0)
      cout << endl;
  }
}

// Get the start day of the first day in a month
int MyCalendar::getStartDay()
{
  // Get total number of days since 1//1//1800
  int startDay1800 = 3;
  int totalNumberOfDays = getTotalNumberOfDays();

  // Return the start day
  return (totalNumberOfDays + startDay1800) % 7;
}

// Get the total number of days since January 1, 1800
int MyCalendar::getTotalNumberOfDays()
{
  int total = 0;

  // Get the total days from 1800 to year - 1
  for (int i = 1800; i < year; i++)
    if (isLeapYear(i))
      total = total + 366;
    else
      total = total + 365;

  // Add days from Jan to the month prior to the calendar month
  for (int i = 1; i < month; i++)
    total = total + getNumberOfDaysInMonth(year, i);

  return total;
}

// Get the number of days in a month
int MyCalendar::getNumberOfDaysInMonth(int year, int month)
{
  if (month == 1 || month == 3 || month == 5 || month == 7 ||
      month == 8 || month == 10 || month == 12)
    return 31;

  if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;

  if (month == 2) return isLeapYear(year) ? 29 : 28;

    system("pause");
  return 0; // If month is incorrect
}

// Determine if it is a leap year
bool MyCalendar::isLeapYear(int year)
{
  return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
