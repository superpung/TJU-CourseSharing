#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double computeTax(int status, double income);

int main()
{
  // Prompt the user to enter filing status
  cout << "Enter the filing status\n" <<
    "\t(0-single, 1-joint, 2-separate, 3-head of house hold): ";
  int status;
  cin >> status;

  // Prompt the user to enter taxable income
  cout << "Enter the taxable income: ";
  double income;
  cin >> income;

  // Display the result
  cout << "Tax is " << fixed << setprecision(2)
    << computeTax(status, income);

    system("pause");
  return 0;
}

double computeTax(
  double income, int r1, int r2, int r3, int r4, int r5)
{
  double tax = 0;

  if (income <= r1)
    tax = income * 0.10;
  else if (income <= r2)
    tax = r1 * 0.10 + (income - r1) * 0.15;
  else if (income <= r3)
    tax = r1 * 0.10 + (r2 - r1) * 0.15 + (income - r2) * 0.27;
  else if (income <= r4)
    tax = r1 * 0.10 + (r2 - r1) * 0.15 + (r3 - r2) * 0.27 +
      (income - r3) * 0.30;
  else if (income <= r5)
    tax = r1 * 0.10 + (r2 - r1) * 0.15 + (r3 - r2) * 0.27 +
      (r4 - r3) * 0.30 + (income - r4) * 0.35;
  else
    tax = r1 * 0.10 + (r2 - r1) * 0.15 + (r3 - r2) * 0.27 +
      (r4 - r3) * 0.30 + (r5 - r4) * 0.35 + (income - r5) * 0.386;

  return tax;
}

double computeTax(int status, double income)
{
  switch (status)
  {
    case 0:
      return computeTax(income, 6000, 27950, 67700, 141250, 307050);
    case 1:
      return computeTax(income, 12000, 46700, 112850, 171950, 307050);
    case 2:
      return computeTax(income, 6000, 23350, 56425, 85975, 153525);
    case 3:
      return computeTax(income, 10000, 37450, 96700, 156600, 307050);
    default:
    system("pause");
      return 0;
  }
}
