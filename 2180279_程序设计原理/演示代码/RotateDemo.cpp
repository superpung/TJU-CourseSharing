#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

int main()
{
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  list<int> intList(8);

  ostream_iterator<int> output(cout, " ");
  cout << "array1: ";
  copy(array1, array1 + 8, output);

  rotate(array1, array1 + 3, array1 + 8);
  cout << "\nafter rotate arrays, array1: ";
  copy(array1, array1 + 8, output);

  rotate_copy(array1, array1 + 1, array1 + 8, intList.begin());
  cout << "\nafter rotate_copy, array1: ";
  copy(array1, array1 + 8, output);
  cout << "\nafter rotate_copy, intList: ";
  copy(intList.begin(), intList.end(), output);

    system("pause");
  return 0;
}
