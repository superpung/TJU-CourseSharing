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

  remove(values, values + 8, 3);
  remove_if(intList.begin(), intList.end(), greaterThan3);

  cout << "\nAfter the remove function, values: ";
  copy(values, values + 8, output);
  cout << "\nAfter the remove_if function, intList: ";
  copy(intList.begin(), intList.end(), output);

    system("pause");
  return 0;
}
