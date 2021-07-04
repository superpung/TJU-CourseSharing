#include <iostream>
using namespace std;

int main()
{
  // Initialize sum
  double sum = 0;

  // Add 0.01, 0.02, ..., 0.99, 1 to sum
  for (double i = 0.01f; i <= 1.0f; i = i + 0.01f)
    sum += i;

  // Display result
  cout << "The sum is " << sum;

    system("pause");
  return 0;
}
