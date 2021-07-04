#ifndef IMPROVEDSTACK_H
#define IMPROVEDSTACK_H

template<typename T>
class Stack
{
public:
  Stack();
  bool empty();
  T peek();
  void push(T value);
  T pop();
  int getSize();

private:
  T *elements;
  int size;
  int capacity;
  void ensureCapacity();
};

template<typename T>
Stack<T>::Stack(): size(0), capacity(16)
{
  elements = new T[capacity];
}

template<typename T>
bool Stack<T>::empty()
{
  return (size == 0);
}

template<typename T>
T Stack<T>::peek()
{
  return elements[size - 1];
}

template<typename T>
void Stack<T>::push(T value)
{
  ensureCapacity();
  elements[size++] = value;
}

template<typename T>
void Stack<T>::ensureCapacity()
{
  if (size >= capacity)
  {
    T *old = elements;
    capacity = 2 * size;
    elements = new T[size * 2];

    for (int i = 0; i < size; i++)
      elements[i] = old[i];

    delete old;
  }
}

template<typename T>
T Stack<T>::pop()
{
  return elements[--size];
}

template<typename T>
int Stack<T>::getSize()
{
  return size;
}

#endif
