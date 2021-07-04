#include <iostream>
using namespace std;

int main()
{
  // Keep reading data until the input is 0
  int sum = 0;
  int data = 0;

  do
  {
    sum += data;

    // Read the next data
    cout << "Enter an int value (the program exits " <<
      " if the input is 0): ";
    cin >> data;
  }
  while (data != 0);

  cout << "The sum is " << sum << endl;

    system("pause");
  return 0;
}
