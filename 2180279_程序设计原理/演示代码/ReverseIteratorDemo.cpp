#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> intVector;
  intVector.push_back(10);
  intVector.push_back(30);
  intVector.push_back(20);

  vector<int>::reverse_iterator p1 = intVector.rbegin();
  for (; p1 != intVector.rend(); p1++)
  {
    cout << *p1 << " ";
  }

    system("pause");
  return 0;
}
