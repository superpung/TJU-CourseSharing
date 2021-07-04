#include <iostream>
using namespace std;

void selectionSort(double [], int);
void printArray(double list[], int arraySize); // function prototype

int main()
{
  double list[] = {2, 1, -4, 4};
  selectionSort(list, 4);

  printArray(list, 4);
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

void selectionSort(double list[], int arraySize)
{
  for (int i = arraySize - 1; i >= 1; i--)
  {
    // Find the maximum in the list[0..i]
    double currentMax = list[0];
    int currentMaxIndex = 0;

    for (int j = 1; j <= i; j++)
    {
      if (currentMax < list[j])
      {
        currentMax = list[j];
        currentMaxIndex = j;
      }
    }

    // Swap list[i] with list[currentMaxIndex] if necessary;
    if (currentMaxIndex != i)
    {
      list[currentMaxIndex] = list[i];
      list[i] = currentMax;
    }
  }
}
