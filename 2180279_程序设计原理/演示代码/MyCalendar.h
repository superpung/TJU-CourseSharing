#ifndef MYCALENDAR_H
#define MYCALENDAR_H

class MyCalendar
{
public:
  MyCalendar(int year, int month);
  void printMonth();
  void printMonthTitle();
  void printMonthName();
  void printMonthBody();
  int getStartDay();
  int getTotalNumberOfDays();
  static int getNumberOfDaysInMonth(int year, int month);
  static bool isLeapYear(int year);
  int getYear();
  void setYear(int year);
  int getMonth();
  void setMonth(int month);

private:
  int year;
  int month;
};

#endif
