#include <iostream>
using namespace std;

void swap(int, int);
void swapFirstTwoInArray(int []);

int main()
{
  int a[] = {1, 2};

  // Swap elements using the swap function
  cout << "Before invoking swap" << endl;
  cout << "array is {" << a[0] << ", " << a[1] << "}" << endl;
  swap(a[0], a[1]);
  cout << "After invoking swap" << endl;
  cout << "array is {" << a[0] << ", " << a[1] << "}" << endl;

  // Swap elements using the swapFirstTwoInArray function
  cout << "\nBefore invoking swapFirstTwoInArray" << endl;
  cout << "array is {" << a[0] << ", " << a[1] << "}" << endl;
  swapFirstTwoInArray(a);
  cout << "After invoking swapFirstTwoInArray" << endl;
  cout << "array is {" << a[0] << ", " << a[1] << "}" << endl;

    system("pause");
  return 0;
}

// Swap two variables
void swap(int n1, int n2)
{
  int temp = n1;
  n1 = n2;
  n2 = temp;
}

// Swap the first two elements in the array
void swapFirstTwoInArray(int array[])
{
  int temp = array[0];
  array[0] = array[1];
  array[1] = temp;
}
