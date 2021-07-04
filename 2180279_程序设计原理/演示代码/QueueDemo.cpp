#include <iostream>
#include <queue>
#include <list>
using namespace std;

template<typename T>
void printQueue(T &queue)
{
  while (!queue.empty())
  {
    cout << queue.front() << " ";
    queue.pop();
  }
}

int main()
{
  queue<int> queue1;
  queue<int, list<int> > queue2;

  for (int i = 0; i < 8; i++)
  {
    queue1.push(i);
    queue2.push(i);
  }

  cout << "Contents in queue1: ";
  printQueue(queue1);

  cout << "\nContents in queue2: ";
  printQueue(queue2);

    system("pause");
  return 0;
}
