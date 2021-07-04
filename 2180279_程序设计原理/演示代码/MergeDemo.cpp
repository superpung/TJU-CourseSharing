#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

int main()
{
  int array1[] = {1, 7, 3, 4, 3, 3, 1, 2};
  list<int> intList(8);

  ostream_iterator<int> output(cout, " ");
  cout << "array1: ";
  copy(array1, array1 + 8, output);

  sort(array1, array1 + 3);
  sort(array1 + 3, array1 + 8);
  cout << "\nafter sort partial arrays, array1: ";
  copy(array1, array1 + 8, output);

  merge(array1, array1 + 3, array1 + 3, array1 + 8, intList.begin());
  cout << "\nafter inplace merger, array1: ";
  copy(intList.begin(), intList.end(), output);

  inplace_merge(array1, array1 + 3, array1 + 8);
  cout << "\nafter inplace merger, intList: ";
  copy(array1, array1 + 8, output);

    system("pause");
  return 0;
}
