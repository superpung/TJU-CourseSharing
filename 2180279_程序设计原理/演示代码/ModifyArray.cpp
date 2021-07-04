#include <iostream>
using namespace std;

void m(int, int []);

int main()
{
  int x = 1; // x represents an int value
  int y[10]; // y represents an array of int values

  m(x, y); // Invoke m with arguments x and y

  cout << "x is " << x << endl;
  cout << "y[0] is " << y[0] << endl;

    system("pause");
  return 0;
}

void m(int number, int numbers[])
{
  number = 1001; // Assign a new value to number
  numbers[0] = 5555; // Assign a new value to numbers[0]
}
