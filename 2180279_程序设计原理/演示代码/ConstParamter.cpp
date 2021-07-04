#include <iostream>
using namespace std;

void printArray(int const *, const int); // function prototype

int main()
{
  int list[6] = {11, 12, 13, 14, 15, 16};
  printArray(list, 6);

    system("pause");
  return 0;
}

void printArray(int const *list, const int size)
{
  for (int i = 0; i < size; i++)
    cout << list[i] << " ";
}
