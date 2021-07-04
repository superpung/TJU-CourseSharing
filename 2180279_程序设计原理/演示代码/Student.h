#include <string>
using namespace std;

class Student
{
public:
  Student();
  Student(string firstName, char mi, string lastName, int score);
  void setFirstName(string s);
  void setMi(char mi);
  void setLastName(string s);
  void setScore(int score);
  string getFirstName();
  char getMi();
  string getLastName();
  int getScore();

private:
  string firstName;
  char mi;
  string lastName;
  int score;
};
