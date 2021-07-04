#include "Loan.h"
#include <cmath>
using namespace std;

Loan::Loan()
{
  annualInterestRate = 9.5;
  numberOfYears = 30;
  loanAmount = 100000;
}

Loan::Loan(double annualInterestRate, int numberOfYears,
  double loanAmount)
{
  this->annualInterestRate = annualInterestRate;
  this->numberOfYears = numberOfYears;
  this->loanAmount = loanAmount;
}

double Loan::getAnnualInterestRate()
{
  return annualInterestRate;
}

int Loan::getNumberOfYears()
{
  return numberOfYears;
}

double Loan::getLoanAmount()
{
  return loanAmount;
}

void Loan::setAnnualInterestRate(double annualInterestRate)
{
  this->annualInterestRate = annualInterestRate;
}

void Loan::setNumberOfYears(int numberOfYears)
{
  this->numberOfYears = numberOfYears;
}

void Loan::setLoanAmount(double loanAmount)
{
  this->loanAmount = loanAmount;
}

double Loan::getMonthlyPayment()
{
  double monthlyInterestRate = annualInterestRate / 1200;
  return loanAmount * monthlyInterestRate / (1 -
    (pow(1 / (1 + monthlyInterestRate), numberOfYears * 12)));
}

double Loan::getTotalPayment()
{
  return getMonthlyPayment() * numberOfYears * 12;
}
