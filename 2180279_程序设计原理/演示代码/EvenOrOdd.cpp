#include <iostream>
using namespace std;

int main()
{
  // Prompt the user to enter an integer
  int number;
  cout << "Enter an integer: ";
  cin >> number;

  if (number % 2 == 0)
    cout << number << " is even.";

  if (number % 2 != 0)
    cout << number << " is odd.";
}
