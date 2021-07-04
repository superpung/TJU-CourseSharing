#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

bool greaterThan(int e1, int e2)
{
  return e1 > e2;
}

int main()
{
  int array1[] = {1, 7, 3, 4, 3, 6, 1, 2};
  int array2[] = {9, 96, 21, 3, 2, 3, 1};
  vector<int> intVector(array1, array1 + 8);

  ostream_iterator<int> output(cout, " ");
  cout << "array1: ";
  copy(array1, array1 + 8, output);
  cout << "\nintVector: ";
  copy(intVector.begin(), intVector.end(), output);

  int *p = find_first_of(array1, array1 + 8, array2 + 2, array2 + 4);
  if (p != array1 + 8)
    cout << "\nfind first of {21, 3} in array1 at position "
      << (p - array1);
  else
    cout << "\nnot found";

  vector<int>::iterator itr =
    find_first_of(intVector.begin(), intVector.end(),
      array2 + 2, array2 + 4, greaterThan);
  if (itr != intVector.end())
    cout << "\nfind {21, 3} in intVector at position " <<
      (itr - intVector.begin());
  else
    cout << "\nnot found";

    system("pause");
  return 0;
}
