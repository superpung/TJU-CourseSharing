#include <iostream>
using namespace std;

/** Return the max between two int values */
int max(int num1, int num2)
{
  if (num1 > num2)
    return num1;
  else
    return num2;
}

/** Return the max among three double values */
double max(double num1, double num2, double num3)
{
  return max(max(num1, num2), num3);
}

int main()
{
  // Invoke the max function with int parameters
  cout << "The maximum between 3 and 4 is " << max(3, 4) << endl;

  // Invoke the max function with the double parameters
  cout << "The maximum between 3.0 and 5.4 is "
    << max(3.0, 5.4) << endl;

  // Invoke the max function with three double parameters
  cout << "The maximum between 3.0, 5.4, and 10.14 is "
    << max(3.0, 5.4, 10.14) << endl;

    system("pause");
  return 0;
}

/** Find the max between two double values */
double max(double num1, double num2)
{
  if (num1 > num2)
    return num1;
  else
    return num2;
}


