#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  fstream input;
  input.open("f1.dat", ios::in | ios::binary);
  int value;

 int i = 0;
 while (!input.eof())
  {
    input.read(reinterpret_cast < char * > (& value), sizeof(value));
    cout << value << " ";
    i++;
    if (i % 10 == 0) cout << endl;
  }

  input.close();

    system("pause");
  return 0;
}
