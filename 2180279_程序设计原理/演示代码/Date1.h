#ifndef DATE_H
#define DATE_H

class Date
{
public:
  Date(int newYear, int newMonth, int newDay);
  int getYear();
  void setYear(int newYear);

private:
  int year;
  int month;
  int day;
};

#endif
