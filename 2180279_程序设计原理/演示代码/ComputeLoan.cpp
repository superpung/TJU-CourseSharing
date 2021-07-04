#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Enter yearly interest rate
  cout << "Enter yearly interest rate, for example 8.25: ";
  double annualInterestRate;
  cin >> annualInterestRate;

  // Obtain monthly interest rate
  double monthlyInterestRate = annualInterestRate / 1200;

  // Enter number of years
  cout << "Enter number of years as an integer, for example 5: ";
  int numberOfYears;
  cin >> numberOfYears;

  // Enter loan amount
  cout << "Enter loan amount, for example 120000.95: ";
  double loanAmount;
  cin >> loanAmount;

  // Calculate payment
  double monthlyPayment = loanAmount * monthlyInterestRate / (1
    - 1 / pow(1 + monthlyInterestRate, numberOfYears * 12));
  double totalPayment = monthlyPayment * numberOfYears * 12;

  // Format to keep two digits after the decimal point
  monthlyPayment = static_cast<int>(monthlyPayment * 100) / 100.0;
  totalPayment = static_cast<int>(totalPayment * 100) / 100.0;

  // Display results
  cout << "The monthly payment is " << monthlyPayment <<
    "\nThe total payment is " << totalPayment << endl;

    system("pause");
  return 0;
}
