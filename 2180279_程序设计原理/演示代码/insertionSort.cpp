#include <iostream>
using namespace std;

void insertionSort(double [], int);
void printArray(double list[], int arraySize); // function prototype

int main()
{
  double list[] = {2, 1, -4, 4, -3};
  insertionSort(list, 5);

  printArray(list, 5);
    system("pause");
  return 0;
}

void printArray(double list[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    cout << list[i] <<  " ";
  }
}

void insertionSort(double list[], int arraySize)
  {
  for (int i = 1; i < arraySize; i++)
  {
    /* insert list[i] into a sorted sublist list[0..i-1] so that
       list[0..i] is sorted. */
    double currentElement = list[i];
    int k;
    for (k = i - 1; k >= 0 && list[k] > currentElement; k--)
    {
      list[k + 1] = list[k];
    }

    // Insert the current element into list[k+1]
    list[k + 1] = currentElement;
  }
}
