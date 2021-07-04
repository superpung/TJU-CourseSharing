#include <iostream>
using namespace std;

int main()
{
  int count = 5;
  int *pCount = &count;

  cout << "The address of count is " << &count << endl;
  cout << "The address of count is " << pCount << endl;
  cout << "The value of count is " << count << endl;
  cout << "The value of count is " << *pCount << endl;

    system("pause");
  return 0;
}
