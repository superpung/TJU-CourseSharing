#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

int nextNum()
{
  static int n = 20;
  return n++;
}

int main()
{
  int values[] = {1, 2, 3, 4, 5, 6};
  list<int> intList(values, values + 6);

  ostream_iterator<int> output(cout, " ");
  cout << "Initial contents, values: ";
  copy(values, values + 6, output);
  cout << "\nInitial contents, intList: ";
  copy(intList.begin(), intList.end(), output);

  generate(values + 2, values + 4, nextNum);
  generate_n(intList.begin(), 2, nextNum);

  cout << "\nAfter the fill function, values: ";
  copy(values, values + 6, output);
  cout << "\nAfter the fill_n function, intList: ";
  copy(intList.begin(), intList.end(), output);

  system("pause");
  return 0;
}
