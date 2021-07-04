#include <iostream>
#include <stdexcept>
using namespace std;

int f1() throw()
{
  try
  {
    throw runtime_error("Exception in f1");
  }
  catch (exception &ex)
  {
    cout << "Exception caught in function f1" << endl;
    cout << ex.what() << endl;
    throw; // rethrow the exception
  }
}

int main()
{
  try
  {
    f1();
  }
  catch (exception &ex)
  {
    cout << "Exception caught in function main" << endl;
    cout << ex.what() << endl;
  }
  system("pause");
  return 0; 
}
