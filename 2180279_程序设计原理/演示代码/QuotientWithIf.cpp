#include <iostream>
using namespace std;

int main()
{
  // Read two intergers
  cout << "Enter two integers: ";
  int number1, number2;
  cin >> number1 >> number2;

  if (number2 != 0)
  {
    cout << number1 << " / " << number2 << " is "
      << (number1 / number2) << endl;
  }
  else
  {
    cout << "Divisor cannot be zero" << endl;
  }
  system("pause");
  return 0; 
}
