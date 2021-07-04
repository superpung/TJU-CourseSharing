#include "StackOfIntegers.h"

StackOfIntegers::StackOfIntegers()
{
  size = 0;
}

bool StackOfIntegers::empty()
{
  return (size == 0);
}

int StackOfIntegers::peek()
{
    return elements[size - 1];
}

int StackOfIntegers::push(int value)
{
  return elements[size++] = value;
}

int StackOfIntegers::pop()
{
  return elements[--size];
}

int StackOfIntegers::getSize()
{
  return size;
}
