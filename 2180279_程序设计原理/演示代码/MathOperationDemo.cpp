#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
using namespace std;

int main()
{
  int array1[] = {1, 2, 3, 4, 5};
  vector<int> intVector(5);

  ostream_iterator<int> output(cout, " ");
  cout << "array1: ";
  copy(array1, array1 + 5, output);

  cout << "\nSum of array1: " <<
    accumulate(array1, array1 + 5, 0) << endl;

  cout << "Product of array1: " <<
    accumulate(array1, array1 + 5, 1, multiplies<int>()) << endl;

  vector<int>::iterator last =
    adjacent_difference(array1, array1 + 5, intVector.begin());
  cout << "After adjacent difference, intVector: ";
  copy(intVector.begin(), last, output);

  cout << "\nInner product of array1 * array1 is " <<
   inner_product(array1, array1 + 5, array1, 0);

  last = partial_sum(array1, array1 + 5, intVector.begin());
  cout << "\nAfter partial sum, intVector: ";
  copy(intVector.begin(), last, output);

    system("pause");
  return 0;
}
