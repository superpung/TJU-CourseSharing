#include <iostream>
#include "StackWithLinkedList.h"
#include <string>
using namespace std;

int main()
{
  Stack<int> stack1;

  for (int i = 0; i < 10; i++)
    stack1.push(i);

  while (!stack1.empty())
    cout << stack1.pop() << " ";
  cout << endl;

  Stack<string> stack1;
  stack1.push("A");
  stack1.push("B");
  stack1.push("C");

  while (!stack1.empty())
    cout << (stack1.pop()) << " ";

    system("pause");
  return 0;
}
