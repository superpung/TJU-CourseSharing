class Time
{
public:
  Time(int hour, int minute, int second)
  {
     // Code omitted
  }

private:
  int hour;
  int minute;
  int second;
};

class Action
{
public:
  Action(int hour, int minute, int second)
    :time(hour, minute, second)
  {
  }

private:
  Time time;
};
