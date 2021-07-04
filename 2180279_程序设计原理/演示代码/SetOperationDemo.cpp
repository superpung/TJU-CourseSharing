#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int array2[] = {1, 3, 6, 9, 12};
  vector<int> intVector(15);

  ostream_iterator<int> output(cout, " ");
  cout << "array1: ";
  copy(array1, array1 + 8, output);
  cout << "\narray2: ";
  copy(array2, array2 + 5, output);

  bool isContained =
    includes(array1, array1 + 8, array2, array2 + 3);
  cout << (isContained ? "\n{1, 3, 6} is a subset of array1" :
    "\n{1, 3, 6} is not a subset of array1");

  vector<int>::iterator last = set_union(array1, array1 + 8,
    array2, array2 + 5, intVector.begin());
  cout << "\nAfter union, intVector: ";
  copy(intVector.begin(), last, output);

  last = set_difference(array1, array1 + 8,
    array2, array2 + 5, intVector.begin());
  cout << "\nAfter difference, intVector: ";
  copy(intVector.begin(), last, output);

  last = set_intersection(array1, array1 + 8,
    array2, array2 + 5, intVector.begin());
  cout << "\nAfter intersection, intVector: ";
  copy(intVector.begin(), last, output);

  last = set_symmetric_difference(array1, array1 + 8,
    array2, array2 + 5, intVector.begin());
  cout << "\nAfter symmetric difference, intVector: ";
  copy(intVector.begin(), last, output);

    system("pause");
  return 0;
}
