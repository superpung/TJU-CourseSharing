#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  ostream_iterator<int> output(cout, " ");
  cout << "array1: ";
  copy(array1, array1 + 8, output);

  cout << "\nafter swap variables, array1: ";
  swap(array1[0], array1[1]);
  copy(array1, array1 + 8, output);

  cout << "\nafter swap via pointers, array1: ";
  iter_swap(array1 + 2, array1 + 3);
  copy(array1, array1 + 8, output);

  cout << "\nafter swap ranges, array1: ";
  swap_ranges(array1, array1 + 4, array1 + 4);
  copy(array1, array1 + 8, output);

    system("pause");
  return 0;
}
