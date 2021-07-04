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

  reverse(array1, array1 + 8);
  cout << "\nafter reverse arrays, array1: ";
  copy(array1, array1 + 8, output);

  reverse_copy(array1, array1 + 8, intList.begin());
  cout << "\nafter reverse_copy, array1: ";
  copy(array1, array1 + 8, output);
  cout << "\nafter reverse_copy, intList: ";
  copy(intList.begin(), intList.end(), output);

    system("pause");
  return 0;
}
