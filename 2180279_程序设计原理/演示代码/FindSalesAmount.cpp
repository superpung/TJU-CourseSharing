#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // The commission sought
  const double COMMISSION_SOUGHT = 25000;
  const double INITIAL_SALES_AMOUNT = 0.01;
  double commission = 0;
  double salesAmount = INITIAL_SALES_AMOUNT;

  do
  {
    // Increase salesAmount by 1 cent
    salesAmount += 0.01;

    // Compute the commission from the current salesAmount;
    if (salesAmount >= 10000.01)
      commission =
        5000 * 0.08 + 5000 * 0.1 + (salesAmount - 10000) * 0.12;
    else if (salesAmount >= 5000.01)
      commission = 5000 * 0.08 + (salesAmount - 5000) * 0.10;
    else
      commission = salesAmount * 0.08;
  }
  while (commission < COMMISSION_SOUGHT);

  // Display the sales amount
  cout << "The sales amount $" << fixed << setprecision(2) <<
    (salesAmount * 100) / 100.0 <<
    "\nis needed to make a commission of $" << COMMISSION_SOUGHT;

    system("pause");
  return 0;
}
