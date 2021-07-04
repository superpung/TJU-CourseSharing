#include <iostream>
#include <queue>
#include <deque>
using namespace std;

template<typename T>
void printQueue(T &priority_queue)
{
  while (!priority_queue.empty())
  {
    cout << priority_queue.top() << " ";
    priority_queue.pop();
  }
}

int main()
{
  priority_queue<int> priority_queue1;
  priority_queue<int, deque<int> > priority_queue2;

  for (int i = 0; i < 8; i++)
  {
    priority_queue1.push(i);
    priority_queue2.push(i);
  }

  cout << "Contents in priority_queue1: ";
  printQueue(priority_queue1);

  cout << "\nContents in priority_queue2: ";
  printQueue(priority_queue2);

    system("pause");
  return 0;
}
