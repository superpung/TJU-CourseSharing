#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream binaryio;
  binaryio.open("city.dat", ios::in | ios::binary);
  char s[10];
  binaryio.read(s, 5);
  s[5] = '\0';
  cout << s;
  binaryio.close();

    system("pause");
  return 0;
}
