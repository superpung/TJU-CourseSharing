#include <iostream>
#include "BubbleSort.h"
using namespace std;

int main()
{
  //    int list[] = {322, 39, 5, 4, 8, 1, 6, 7, 4, 2, 3};
  int list[] =
  {
    10, 19, 8, 7, 36, 5, 4, 3, 2, 1
  }; //, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  bubbleSort(list, 10);
  for (int i = 0; i < 10; i++)
  {
    cout << list[i] << " ";
  }

    system("pause");
  return 0;
}
