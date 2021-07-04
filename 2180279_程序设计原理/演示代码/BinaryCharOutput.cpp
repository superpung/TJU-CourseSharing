#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream binaryio;
  binaryio.open("city.dat", ios::out | ios::binary);
  char s[] = "Atlanta";
  binaryio.write(s, 5);
  binaryio.close();

  cout << "Done" << endl;
    system("pause");
  return 0;
}
