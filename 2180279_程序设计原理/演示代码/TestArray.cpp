#include <iostream>
using namespace std;

int main()
{
  const int TOTAL_NUMBERS = 6;
  int numbers[TOTAL_NUMBERS];

  // Read all numbers
  for (int i = 0; i < TOTAL_NUMBERS; i++)
  {
    cout << "Enter a number: ";
    cin >> numbers[i];
  }

  // Find the largest
  int max = numbers[0];
  for (int i = 1; i < TOTAL_NUMBERS; i++)
  {
    if (max < numbers[i])
      max = numbers[i];
  }

  // Find the occurrence of the largest number
  int count = 0;
  for (int i = 0; i < TOTAL_NUMBERS; i++)
  {
    if (numbers[i] == max) count++;
  }

  // Display the result
  cout << "The array is ";
  for (int i = 0; i < TOTAL_NUMBERS; i++)
  {
    cout << numbers[i] << " ";
  }

  cout << "\nThe largest number is " << max;
  cout << "\nThe occurrence count of the largest number is "
       << count;

    system("pause");
  return 0;
}
