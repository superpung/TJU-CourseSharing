#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // Prompt the user to enter the number of lines
  cout << "Enter the number of lines: ";
  int numberOfLines;
  cin >> numberOfLines;

  if (numberOfLines < 1 || numberOfLines > 15)
  {
    cout << "You must enter a number from 1 to 15";
    system("pause");
    return 0;
  }

  // Print lines
  for (int row = 1; row <= numberOfLines; row++)
  {
    // Print NUMBER_OF_LINES – row) leading spaces
    for (int column = 1; column <= numberOfLines - row; column++)
      cout << "   ";

    // Print leading numbers row, row – 1, ..., 1
    for (int num = row; num >= 1; num--)
      cout << setw(3) << num;

    // Print ending numbers 2, 3, ..., row – 1, row
    for (int num = 2; num <= row; num++)
      cout << setw(3) << num;

    // Start a new line
    cout << endl;
  }

    system("pause");
  return 0;
}
