#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

void display(int &value)
{
  cout << value << " ";
}

int square(int &value)
{
  return value * value;
}

int main()
{
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  cout << "array1: ";
  for_each(array1, array1 + 8, display);

  vector<int> intVector(8);
  transform(array1, array1 + 8, intVector.begin(), square);
  cout << "\nintVector: ";
  for_each(intVector.begin(), intVector.end(), display);

    system("pause");
  return 0;
}
