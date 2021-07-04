#include <iostream>
#include <string>
#include "GenericStack.h"
using namespace std;

int main()
{
  Stack<int> intStack;
  for (int i = 0; i < 10; i++)
    intStack.push(i);

  while (!intStack.empty())
    cout << intStack.pop() << " ";
  cout << endl;

  Stack<string> stringStack;
  stringStack.push("Chicago");
  stringStack.push("Denver");
  stringStack.push("London");

  while (!stringStack.empty())
    cout << stringStack.pop() << " ";

    system("pause");
  return 0;
}
