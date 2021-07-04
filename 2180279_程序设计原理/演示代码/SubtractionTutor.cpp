#include <iostream>
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions
using namespace std;

int main()
{
  // 1. Generate two random single-digit integers
  srand(time(0));
  int number1 = rand() % 10;
  int number2 = rand() % 10;

  // 2. If number1 < number2, swap number1 with number2
  if (number1 < number2)
  {
    int temp = number1;
    number1 = number2;
    number2 = temp;
  }

  // 3. Prompt the student to answer “what is number1 – number2?”
  cout << "What is " << number1 << " - " << number2 << "? ";
  int answer;
  cin >> answer;

  // 4. Grade the answer and display the result
  if (number1 - number2 == answer)
    cout << "You are correct!";
  else
    cout << "Your answer is wrong.\n" << number1 << " - " << number2
         << " should be " << (number1 - number2) << endl;

    system("pause");
  return 0;
}
