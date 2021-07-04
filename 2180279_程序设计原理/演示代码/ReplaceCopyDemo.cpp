#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

bool greaterThan3(int value)
{
  return value > 3;
}

int main()
{
  int values[] = {1, 7, 3, 4, 3, 6, 1, 2};
  list<int> intList(values, values + 8);

  ostream_iterator<int> output(cout, " ");
  cout << "Initial contents, values: ";
  copy(values, values + 8, output);
  cout << "\nInitial contents, intList: ";
  copy(intList.begin(), intList.end(), output);

  int newValues[] = {9, 9, 9, 9, 9, 9, 9, 9};
  list<int> newIntList(values, values + 8);
  replace_copy(values + 2, values + 5, newValues, 3, 88);
  replace_copy_if(intList.begin(), intList.end(),
    newIntList.begin(), greaterThan3, 88);

  cout << "\nAfter the replace function, values: ";
  copy(values, values + 8, output);
  cout << "\nAfter the replace_if function, intList: ";
  copy(intList.begin(), intList.end(), output);
  cout << "\nAfter the replace_copy function, newValues: ";
  copy(newValues, newValues + 8, output);
  cout << "\nAfter the replace_copy_if function, newIntList: ";
  copy(newIntList.begin(), newIntList.end(), output);

    system("pause");
  return 0;
}
