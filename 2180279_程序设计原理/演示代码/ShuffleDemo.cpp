#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8};
  random_shuffle(array1, array1 + 8);
  cout << "After random shuffle, array1: ";
  ostream_iterator<int> output(cout, " ");
  copy(array1, array1 + 8, output);

    system("pause");
  return 0;
}
