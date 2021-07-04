#include <iostream>
using namespace std;

void p( int const list[], int arraySize)
{
  // Modify array accidentally
  cout<<list[0]<<endl;
  //list[0] = 100; // Compile error!
}

int main()
{
  int numbers[5] = {1, 4, 3, 6, 8};
  p(numbers, 5);

    system("pause");
  return 0;
}
