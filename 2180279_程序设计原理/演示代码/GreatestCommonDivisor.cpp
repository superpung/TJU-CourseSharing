#include <iostream>
using namespace std;

int main()
{
  // Prompt the user to enter two integers
  cout << "Enter first integer: ";
  int n1;
  cin >> n1;

  cout << "Enter second integer: ";
  int n2;
  cin >> n2;

  int gcd = 1;
  int k = 1;
  while (k <= n1 && k <= n2)
  {
    if (n1 % k == 0 && n2 % k == 0)
      gcd = k;
    k++;
  }

  cout << "The greatest common divisor for " << n1 << " and "
       << n2 << " is " << gcd;

    system("pause");
  return 0;
}
