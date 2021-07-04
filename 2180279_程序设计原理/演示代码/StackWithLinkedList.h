#ifndef STACKWITHLINKEDLIST_H
#define STACKWITHLINKEDLIST_H
#include "LinkedList.h"

template<typename T>
class Stack
{
public:
  Stack();
  bool empty();
  T peek();
  T push(T value);
  T pop();
  int getSize();

private:
  LinkedList<T> list;
};

template<typename T>
Stack<T>::Stack()
{
}

template<typename T>
bool Stack<T>::empty()
{
  return list.isEmpty();
}

template<typename T>
T Stack<T>::peek()
{
  return list.getLast();
}

template<typename T>
T Stack<T>::push(T value)
{
  list.addLast(value);
  return value;
}

template<typename T>
T Stack<T>::pop()
{
  return list.removeLast();
}

template<typename T>
int Stack<T>::getSize()
{
  return list.getSize();
}

#endif
