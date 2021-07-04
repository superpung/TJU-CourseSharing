#include <iostream>
using namespace std;

int main()
{
  // Enter a degree in Fahrenheit
  double fahrenheit;
  cout << "Enter a degree in Fahrenheit: ";
  cin >> fahrenheit;

  // Obtain a celsius degree
  double celsius = (5.0 / 9) * (fahrenheit - 32);

  // Display result
  cout << "Fahrenheit " << fahrenheit << " is " <<
      celsius << " in Celsius" << endl;

    system("pause");
  return 0;
}
