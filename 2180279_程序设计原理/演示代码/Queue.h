#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
#include <stdexcept>
using namespace std;

template<typename T>
class Queue
{
public:
  Queue();
  void enqueue(T element);
  T dequeue() throw (runtime_error);
  int getSize();

private:
  LinkedList<T> list;
};

template<typename T>
Queue<T>::Queue()
{
}

template<typename T>
void Queue<T>::enqueue(T element)
{
  list.addLast(element);
}

template<typename T>
T Queue<T>::dequeue() throw (runtime_error)
{
  return list.removeFirst();
}

template<typename T>
int Queue<T>::getSize()
{
  return list.getSize();
}

#endif
