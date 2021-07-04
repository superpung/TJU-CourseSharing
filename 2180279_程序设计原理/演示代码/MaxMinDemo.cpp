#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8};

  cout << "The max element in array1: " <<
    *max_element(array1, array1 + 8) << endl;

  cout << "The min element in array1: " <<
    *min_element(array1, array1 + 8) << endl;

    system("pause");
  return 0;
}
