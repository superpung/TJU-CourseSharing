#include <iostream>
#include <iterator>
#include <cmath>
using namespace std;

int main()
{
  cout << "Enter three numbers: ";
  istream_iterator<int> inputIterator(cin);
  ostream_iterator<int> outputIterator(cout);

  int number1 = *inputIterator;
  inputIterator++;
  int number2 = *inputIterator;
  inputIterator++;
  int number3 = *inputIterator;

  cout << "The largest number is ";
  *outputIterator = max(max(number1, number2), number3);

    system("pause");
  return 0;
}
