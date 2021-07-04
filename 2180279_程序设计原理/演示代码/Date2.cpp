#include "Date2.h"

Date::Date(int newYear, int newMonth, int newDay)
{
  year = newYear;
  month = newMonth;
  day = newDay;
}

int Date::getYear()
{
  return year;
}

void Date::setYear(int newYear)
{
  year = newYear;
}
