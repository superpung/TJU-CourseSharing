#include <iostream>
using namespace std;

int main()
{
  int count = 1;
  int &refCount = count;
  refCount++;

  cout << "count is " << count << endl;
  cout << "refCount is " << refCount << endl;

    system("pause");
  return 0;
}
