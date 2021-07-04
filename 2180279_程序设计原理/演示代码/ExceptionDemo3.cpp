#include <typeinfo>
#include <iostream>
#include <stdexcept>
using namespace std;

int quotient(int number1, int number2)
{
  if (number2 == 0)
    throw runtime_error("Runtime error in quotient");

  return number1 / number2;
}

int main()
{
  // Read two intergers
  cout << "Enter two integers: ";
  int number1, number2;
  cin >> number1 >> number2;

  try
  {
    int result = quotient(number1, number2);
    cout << number1 << " / " << number2 << " is "
      << result << endl;
  }
  catch (exception &e)
  {
    cout << "Exception: " << e.what() << endl;
    cout << "Exception type: " << typeid(e).name() << endl;
  }

  cout << "Execution continues ..." << endl;
  system("pause");
  return 0; 
}
