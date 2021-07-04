#include <iostream>
using namespace std;

int main()
{
  try
  {
    for (int i = 1; i <= 100; i++)
    {
      new int[70000000];
      cout << i << " arrays have been created" << endl;
    }
  }
  catch (bad_alloc &e)
  {
    cout << "Exception: " << e.what() << endl;
  }
  system("pause");
  return 0; 
}
