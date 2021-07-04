#include <iostream>
using namespace std;

int linearSearch(int [], int, int);

int main()
{
  int list[] = {1, 4, 4, 2, 5, -3, 6, 2};
  int i = linearSearch(list, 4, 8);  // returns 1
  int j = linearSearch(list, -4, 8); // returns -1
  int k = linearSearch(list, -3, 8); // returns 5

  cout << i << " " << j << " " << k << endl;
    system("pause");
  return 0;
}

int linearSearch(int list[], int key, int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    if (key == list[i])
      return i;
  }

  return -1;
}
