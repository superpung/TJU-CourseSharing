#include <iostream>
using namespace std;

// Return the factorial for a specified index
int factorial(int);

int main()
{
  // Prompt the user to enter an integer
  cout << "Please enter a non-negative integer: ";
  int n;
  cin >> n;

  // Display factorial
  cout << "Factorial of " << n << " is " << factorial(n);

    system("pause");
  return 0;
}

// Return the factorial for a specified index
int factorial(int n)
{
  if (n == 0) // Base case
    return 1;
  else
    return n * factorial(n - 1); // Recursive call
}
