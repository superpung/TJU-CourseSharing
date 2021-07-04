#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
  int array1[] = {1, 7, 3, 4, 3, 6, 1, 2};
  int array2[] = {3, 6, 1};
  vector<int> intVector(array1, array1 + 8);

  ostream_iterator<int> output(cout, " ");
  cout << "array1: ";
  copy(array1, array1 + 8, output);
  cout << "\nintVector: ";
  copy(intVector.begin(), intVector.end(), output);

  int *p = find_end(array1, array1 + 8, array2, array2 + 1);
  if (p != array1 + 8)
    cout << "\nfind {3} in array1 at position " << (p - array1);
  else
    cout << "\nnot found";

  vector<int>::iterator itr =
    find_end(intVector.begin(), intVector.end(), array2 + 1, array2 + 2);
  if (itr != intVector.end())
    cout << "\nfind {6, 1} in intVector at position " <<
      (itr - intVector.begin());
  else
    cout << "\nnot found";

    system("pause");
  return 0;
}
