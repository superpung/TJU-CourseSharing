#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

int main()
{
  int array1[] = {1, 7, 3, 4, 3, 3, 1, 2};

  ostream_iterator<int> output(cout, " ");
  cout << "Before sort, array1: ";
  copy(array1, array1 + 8, output);

  sort(array1, array1 + 8);

  cout << "\nAfter sort, array1: ";
  copy(array1, array1 + 8, output);

  cout << (binary_search(array1, array1 + 8, 4) ?
    "\n4 is in array1" : "\n4 is not in array1");

  sort(array1, array1 + 8, greater_equal<int>());

  cout << "\nAfter sort with function operator(>=), array1: ";
  copy(array1, array1 + 8, output);

  cout << (binary_search(array1, array1 + 8, 4,
    greater_equal<int>()) ?
    "\n4 is in array1" : "\n4 is not in array1");

    system("pause");
  return 0;
}

