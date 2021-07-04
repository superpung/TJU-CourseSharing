#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> intVector;
  intVector.push_back(10);
  intVector.push_back(20);
  intVector.push_back(30);
  intVector.push_back(40);
  intVector.push_back(50);
  intVector.push_back(60);

  vector<int>::iterator p1 = intVector.begin();
  for (; p1 != intVector.end(); p1++)
  {
    cout << *p1 << " ";
  }

  cout << endl << *(--p1) << endl;
  cout << *(p1 - 3) << endl;
  cout << p1[-3] << endl;
  *p1 = 1234;
  cout << *p1 << endl;

    system("pause");
  return 0;
}
