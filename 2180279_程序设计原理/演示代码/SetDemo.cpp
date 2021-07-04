#include <iostream>
#include <set>
using namespace std;

int main()
{
  int values[] = {3, 5, 1, 7, 2, 2};
  set<int> set1(values, values + 6);

  cout << "Initial contents in set1: ";
  multiset<int>::iterator p;
  for (p = set1.begin(); p != set1.end(); p++)
    cout << *p << " ";

  set1.insert(555);
  set1.insert(1);
  cout << "\nAfter the insert function, set1: ";
  for (p = set1.begin(); p != set1.end(); p++)
    cout << *p << " ";

  p = set1.lower_bound(2);
  cout << "\nLower bound of 2 in set1: " << *p;
  p = set1.upper_bound(2);
  cout << "\nUpper bound of 2 in set1: " << *p;

  p = set1.find(2);
  if (p == set1.end())
    cout << "2 is not in set1" << endl;
  else
    cout << "\nThe number of 2's in set1: " << set1.count(2);

  set1.erase(2);
  cout << "\nAfter the erase function, set1: ";
  for (p = set1.begin(); p != set1.end(); p++)
    cout << *p << " ";

    system("pause");
  return 0;
}
