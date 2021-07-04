#include <iostream>
#include <string>
#include "ImprovedStack.h"
using namespace std;

template<typename T>
void printStack(const Stack<T> &stack)
{
  while (!stack.empty())
    cout << stack.pop() << " ";
  cout << endl;
}

int main()
{
  // Create a stack of int values
  Stack<int> intStack;
  for (int i = 0; i < 20; i++)
    intStack.push(i);
  printStack(intStack);

    system("pause");
  return 0;
}
