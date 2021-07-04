#include "Heap.h"

template <typename T>
void heapSort(T list[], int arraySize)
{
  Heap<T> heap;

  for (int i = 0; i < arraySize; i++)
    heap.add(list[i]);

  for (int i = 0; i < arraySize; i++)
    list[i] = heap.remove();
}
