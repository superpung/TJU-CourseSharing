#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> intVector;
  intVector.push_back(10);

  vector<int>::iterator p1 = intVector.begin();
  vector<int>::const_iterator p2 = intVector.begin();

  *p1 = 123; // OK
  *p2 = 123; // Not allowed

  cout << *p1 << endl;
  cout << *p2 << endl;

    system("pause");
  return 0;
}
