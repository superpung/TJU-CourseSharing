#include <iostream>
#include <string>
using namespace std;

template<typename T>
void sort(T list[], int arraySize)
{
  for (int i = arraySize - 1; i >= 1; i--)
  {
    // Find the maximum in the list[0..i]
    T currentMax = list[0];
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

template<typename T>
void printArray(T list[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}

int main()
{
  int list1[] = {3, 5, 1, 0, 2, 8, 7};
  sort(list1, 7);
  printArray(list1, 7);

  double list2[] = {3.5, 0.5, 1.4, 0.4, 2.5, 1.8, 4.7};
  sort(list2, 7);
  printArray(list2, 7);

  string list3[] = {"Atlanta", "Denver", "Chicago", "Dallas"};
  sort(list3, 4);
  printArray(list3, 4);
  system("pause");
  return 0; 
}
