#include <iostream>
using namespace std;

int main()
{
  // Read two intergers
  cout << "Enter two integers: ";
  int number1, number2;
  cin >> number1 >> number2;

  try
  {
    if (number2 == 0)
      throw number1;

    cout << number1 << " / " << number2 << " is "
      << (number1 / number2) << endl;
  }
  catch (int e)
  {
    cout << "Exception: an integer " << e <<
      " cannot be divided by zero" << endl;
  }

  cout << "Execution continues ..." << endl;
  system("pause");
  return 0; 
}
