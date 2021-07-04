#include <iostream>
using namespace std;

int binarySearch(const int list[], int key, int low, int high)
{
  if (low > high)  // The list has been exhausted without a match
    return -low - 1; // Return -insertion point - 1

  int mid = (low + high) / 2;
  if (key < list[mid])
    return binarySearch(list, key, low, mid - 1);
  else if (key == list[mid])
    return mid;
  else
    return binarySearch(list, key, mid + 1, high);
}

int binarySearch(const int list[], int key, int size)
{
  int low = 0;
  int high = size - 1;
  return binarySearch(list, key, low, high);
}

int main()
{
  int list[] = {2, 4, 7, 10, 11, 45, 50, 59, 60, 66, 69, 70, 79};
  int i = binarySearch(list, 2, 13); // returns 0
  int j = binarySearch(list, 11, 13); // returns 4
  int k = binarySearch(list, 12, 13); // returns –6

  cout << "binarySearch(list, 2, 13) returns " << i << endl;
  cout << "binarySearch(list, 11, 13) returns " << j << endl;
  cout << "binarySearch(list, 12, 13) returns " << k << endl;

    system("pause");
  return 0;
}
