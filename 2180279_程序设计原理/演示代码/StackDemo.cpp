#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template<typename T>
void printStack(T &stackRef)
{
  while (!stackRef.empty())
  {
    cout << stackRef.top() << " ";
    stackRef.pop();
  }
}

int main()
{
  stack<int> stack1;
  stack<int, vector<int> > stack2;

  for (int i = 0; i < 8; i++)
  {
    stack1.push(i);
    stack2.push(i);
  }

  cout << "Contents in stack1: ";
  printStack(stack1);

  cout << "\nContents in stack2: ";
  printStack(stack2);

    system("pause");
  return 0;
}
