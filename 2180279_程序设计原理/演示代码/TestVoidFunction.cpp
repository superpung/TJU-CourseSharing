#include <iostream>
using namespace std;

/** Print grade for the score */
void printGrade(double score)
{
  if (score < 0 || score > 100) {
    cout << "Invalid score";
    return;
  }

  if (score >= 90.0)
    cout << 'A';
  else if (score >= 80.0)
    cout << 'B';
  else if (score >= 70.0)
    cout << 'C';
  else if (score >= 60.0)
    cout << 'D';
  else
    cout << 'F';
}

int main()
{
  cout << "Enter a score: ";
  double score;
  cin >> score;

  cout << "The grade is ";
  printGrade(score);
    system("pause");
  return 0;
}
