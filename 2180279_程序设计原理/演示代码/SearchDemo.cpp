#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
  int array1[] = {1, 7, 3, 4, 3, 3, 1, 2};
  int array2[] = {9, 96, 4, 3, 2, 3, 1};
  vector<int> intVector(array1, array1 + 8);

  ostream_iterator<int> output(cout, " ");
  cout << "array1: ";
  copy(array1, array1 + 8, output);
  cout << "\nintVector: ";
  copy(intVector.begin(), intVector.end(), output);

  int *p = search(array1, array1 + 8, array2 + 2, array2 + 4);
  if (p != array1 + 8)
    cout << "\nSearch {4, 3} in array1 at position "
      << (p - array1);
  else
    cout << "\nnot found";

  vector<int>::iterator itr =
    search_n(intVector.begin(), intVector.end(), 2, 3);
  if (itr != intVector.end())
    cout << "\nSearch two occurrence of 3 in intVector at position "
      << (itr - intVector.begin());
  else
    cout << "\nnot found";

    system("pause");
  return 0;
}
