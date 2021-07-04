#include <iostream>
using namespace std;

int main()
{
  int seconds = 500;
  int minutes = seconds / 60;
  int remainingSeconds = seconds % 60;
  cout << seconds << " seconds is " << minutes <<
    " minutes and " << remainingSeconds << " seconds " << endl;

    system("pause");
  return 0;
}
