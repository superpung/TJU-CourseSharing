#include <iostream>
#include <algorithm>
using namespace std;

bool greaterThan1(int value)
{
  return value > 1;
}

int main()
{
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8};

  cout << "The number of 1's in array1: " <<
    count(array1, array1 + 8, 1) << endl;

  cout << "The number of elements > 1 in array1: " <<
    count_if(array1, array1 + 8, greaterThan1) << endl;

    system("pause");
  return 0;
}
