#include <iostream>
#include "Queue.h"
#include <string>
using namespace std;

template<typename T>
void printQueue(Queue<T> &queue)
{
  while (queue.getSize() > 0)
    cout << queue.dequeue() << " ";
  cout << endl;
}

int main()
{
  // Queue of int values
  Queue<int> intQueue;
  for (int i = 0; i < 10; i++)
    intQueue.enqueue(i);

  printQueue(intQueue);

  // Queue of strings
  Queue<string> stringQueue;
  stringQueue.enqueue("New York");
  stringQueue.enqueue("Boston");
  stringQueue.enqueue("Denver");

  printQueue(stringQueue);

    system("pause");
  return 0;
}
