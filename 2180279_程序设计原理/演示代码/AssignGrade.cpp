#include <iostream>
using namespace std;

int main()
{
  // Maximum number of students
  const int NUMBER_OF_STUDENTS = 5;
  int scores[NUMBER_OF_STUDENTS]; // Array scores
  int best = 0; // The best score
  char grade; // The grade

  // Read scores and find the best score
  for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
  {
    cout << "Please enter a score: ";
    cin >> scores[i];
    if (scores[i] > best)
      best = scores[i];
  }

  // Assign and display grades
  for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
  {
    if (scores[i] >= best - 10)
      grade = 'A';
    else if (scores[i] >= best - 20)
      grade = 'B';
    else if (scores[i] >= best - 30)
      grade = 'C';
    else if (scores[i] >= best - 40)
      grade = 'D';
    else
      grade = 'F';

    cout << "Student " << i << " score is " << scores[i] <<
      " and grade is " << grade << "\n";
  }

    system("pause");
  return 0;
}
