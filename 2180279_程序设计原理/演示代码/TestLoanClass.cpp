#include <iostream>
#include <iomanip>
#include "Loan.h"
using namespace std;

int main()
{
  // Enter annual interest rate
  cout << "Enter yearly interest rate, for example 8.25: ";
  double annualInterestRate;
  cin >> annualInterestRate;

  // Enter number of years
  cout << "Enter number of years as an integer, for example 5: ";
  int numberOfYears;
  cin >> numberOfYears;

  // Enter loan amount
  cout << "Enter loan amount, for example 120000.95: ";
  double loanAmount;
  cin >> loanAmount;

  // Create Loan object
  Loan loan(annualInterestRate, numberOfYears, loanAmount);

  // Display results
  cout << fixed << setprecision(2); 
  cout << "The monthly payment is " << loan.getMonthlyPayment() << endl;
  cout << "The total payment is " << loan.getTotalPayment() << endl;

    system("pause");
  return 0;
}
