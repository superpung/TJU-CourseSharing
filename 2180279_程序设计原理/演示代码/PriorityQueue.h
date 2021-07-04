#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Heap.h"

template<typename T>
class PriorityQueue
{
public:
  PriorityQueue();
  void enqueue(T element);
  T dequeue() throw (runtime_error);
  int getSize();

private:
  Heap<T> heap;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
}

template<typename T>
void PriorityQueue<T>::enqueue(T element)
{
  heap.add(element);
}

template<typename T>
T PriorityQueue<T>::dequeue() throw (runtime_error)
{
  return heap.remove();
}

template<typename T>
int PriorityQueue<T>::getSize()
{
  return heap.getSize();
}

#endif
