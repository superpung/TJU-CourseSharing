#include <iostream>
#include "HeapSort.h"

int main()
{
  int list[] = {3, 2, 1, 4, 5};
  heapSort(list, 5);

  for (int i = 0; i < 5; i++)
    cout << list[i] << " ";

    system("pause");
  return 0;
}
