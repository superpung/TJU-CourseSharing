#include <iostream>
#include <cstring>
using namespace std;

void sort(char list[], int high)
{
  if (high > 0)
  {
    // Find the largest element and its index
    int indexOfMax = 0;
    char max = list[0];
    for (int i = 1; i <= high; i++)
    {
      if (list[i] > max)
      {
        max = list[i];
        indexOfMax = i;
      }
    }

    // Swap the largest with the last element in the list
    list[indexOfMax] = list[high];
    list[high] = max;

    // Sort the remaining list
    sort(list, high - 1);
  }
}

void sort(char list[])
{
  sort(list, strlen(list) - 1);
}

int main()
{
  cout << "Enter a string: ";
  char s[80];
  cin.getline(s, 80);

  sort(s);

  cout << "The sorted string is " << s << endl;

    system("pause");
  return 0;
}
