#include <iostream>
using namespace std;

int maxNumber(int num1, double num2)
{
  if (num1 > num2)
    return num1;
  else
    return num2;
}

double maxNumber(double num1, int num2)
{
  if (num1 > num2)
    return num1;
  else
    return num2;
}

int main()
{
  cout << maxNumber(1, 2) << endl;
    system("pause");
  return 0;
}
