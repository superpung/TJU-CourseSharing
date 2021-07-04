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

  replace(values, values + 8, 3, 747);
  replace_if(intList.begin(), intList.end(), greaterThan3, 747);

  cout << "\nAfter the replace function, values: ";
  copy(values, values + 8, output);
  cout << "\nAfter the replace_if function, intList: ";
  copy(intList.begin(), intList.end(), output);

    system("pause");
  return 0;
}
