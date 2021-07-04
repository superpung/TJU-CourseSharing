#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
  vector<int> intVector;
  intVector.push_back(10);
  intVector.push_back(40);
  intVector.push_back(50);
  intVector.push_back(20);
  intVector.push_back(30);

  vector<int>::iterator p1;
  cout << "Tranverse the vector: ";
  for (p1 = intVector.begin(); p1 != intVector.end(); p1++)
  {
    cout << *p1 << " ";
  }

  set<int> intSet;
  intSet.insert(10);
  intSet.insert(40);
  intSet.insert(50);
  intSet.insert(20);
  intSet.insert(30);

  set<int>::iterator p2;
  cout << "\nTranverse the set: ";
  for (p2 = intSet.begin(); p2 != intSet.end(); p2++)
  {
    cout << *p2 << " ";
  }
  cout << endl;

    system("pause");
  return 0;
}
