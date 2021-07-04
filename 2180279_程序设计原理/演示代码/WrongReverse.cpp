#include <iostream>
using namespace std;

inline int * reverse(int const * list, const int size)
{
  int result[6];

  for (int i = 0, j = size - 1; i < size; i++, j--)
  {
    result[j] = list[i];
  }

  return result;
}

void printArray(int const *list, const int size)
{
  for (int i = 0; i < size; i++)
    cout << list[i] << " ";
}

int main()
{
  int list[] = {1, 2, 3, 4, 5, 6};
  int *pList = reverse(list, 6);
  printArray(pList, 6);

    system("pause");
  return 0;
}
