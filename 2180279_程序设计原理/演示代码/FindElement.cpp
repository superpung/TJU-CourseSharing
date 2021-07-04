#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
  int values[] = {1, 7, 3, 4, 3, 6, 1, 2};
  vector<int> intVector(values, values + 8);

  ostream_iterator<int> output(cout, " ");
  cout << "values: ";
  copy(values, values + 8, output);
  cout << "\nintVector: ";
  copy(intVector.begin(), intVector.end(), output);

  int key;
  cout << "\nEnter a key: ";
  cin >> key;
  cout << "Find " << key << " in values: ";
  int *p = find(values, values + 8, key);
  if (p != values + 8)
    cout << "found at position " << (p - values);
  else
    cout << "not found";

  cout << "\nFind " << key << " in intVector: ";
  vector<int>::iterator itr = find(intVector.begin(), intVector.end(), key);
  if (itr != intVector.end())
    cout << "found at position " << (itr - intVector.begin());
  else
    cout << "not found";

    system("pause");
  return 0;
}
