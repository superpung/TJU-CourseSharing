#include <iostream>
using namespace std;

const int COLUMN_SIZE = 3;

int sum(const int a[][COLUMN_SIZE], int rowSize)
{
  int total = 0;
  for (int row = 0; row < rowSize; row++)
  {
    for (int column = 0; column < COLUMN_SIZE; column++)
    {
      total += a[row][column];
    }
  }

  return total;
}

int main()
{
  int array[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
  };

  cout << "Sum of all elements is " << sum(array, 4) << endl;
    system("pause");
  return 0;
}
