#include <iostream>
#include <iomanip>
using namespace std;

double computeTax(int, double);

int main()
{
  // Prompt the user to enter filing status
  cout << "(0-single filer, 1-married jointly,\n" <<
    "2-married separately, 3-head of household\n" <<
    "Enter the filing status: ";
  int status;
  cin >> status;

  // Prompt the user to enter taxable income
  cout << "Enter the taxable income: ";
  double income;
  cin >> income;

  // Compute and display the result
  cout << "Tax is " << fixed << setprecision(2) <<
    computeTax(status, income);

    system("pause");
  return 0;
}

double computeTax(int status, double income)
{
  const int BRACKET_SIZE = 6;
  double rates[] = {0.10, 0.15, 0.27, 0.30, 0.35, 0.386};

  int brackets[4][5] =
  {
    {6000, 27950, 67700, 141250, 307050}, // Single filer
    {12000, 46700, 112850, 171950, 307050}, // Married jointly
    {6000, 23350, 56425, 85975, 153525}, // Married separately
    {10000, 37450, 96700, 156600, 307050} // Head of household
  };

  double tax = 0; // Tax to be computed

  // Compute tax in the first bracket
  if (income <= brackets[status][0])
    return tax = income * rates[0]; // Done
  else
    tax = brackets[status][0] * rates[0];

  // Compute tax in the 2nd, 3rd, 4th, and 5th brackets, if needed
  for (int i = 1; i < BRACKET_SIZE; i++)
  {
    if (income > brackets[status][i])
      tax += (brackets[status][i] - brackets[status][i - 1]) *
        rates[i];
    else
    {
      tax += (income - brackets[status][i - 1]) * rates[i];
      return tax; // Done
    }
  }

  // Compute tax in the last (i.e., 6th) bracket
  return  tax += (income - brackets[status][4]) * rates[5];
}
