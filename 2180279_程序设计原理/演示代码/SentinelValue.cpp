#include <iostream>
using namespace std;

int main()
{
  cout << "Enter an int value (the program exits " <<
    "if the input is 0): ";
  int data;
  cin >> data;

  // Keep reading data until the input is 0
  int sum = 0;
  while (data != 0)
  {
    sum += data;

    // Read the next data
    cout << "Enter an int value (the program exits " <<
      "if the input is 0): ";
    cin >> data;
  }

  cout << "The sum is " << sum << endl;

    system("pause");
  return 0;
}
