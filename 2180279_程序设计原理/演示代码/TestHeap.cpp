#include <iostream>
#include <string>
#include "Heap.h"
using namespace std;

int main()
{
  Heap<string> heap1;
  heap1.add("George");
  heap1.add("Michael");
  heap1.add("Tom");
  heap1.add("Adam");
  heap1.add("Jones");
  heap1.add("Peter");

  while (heap1.getSize() > 0)
    cout << heap1.remove() << " ";
  cout << endl;

  int numbers[] = {8, 9, 2, 3, 4, 1, 5, 6, 7};
  Heap<int> heap2(numbers, 9);
  while (heap2.getSize() > 0)
    cout << heap2.remove() << " ";

    system("pause");
  return 0;
}
