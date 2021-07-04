#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream binaryio;
  binaryio.open("temp.dat", ios::in | ios::binary);
  int value;
  binaryio.read(reinterpret_cast<char *>(&value), sizeof(value));
  cout << value;
  binaryio.close();

//  fstream inout;
//
//  // Create a file
//  inout.open("city.dat", ios::out | ios::binary);
//
//  // Write int value
//  int value = 199;
//  inout.write(reinterpret_cast < char * > (& value), sizeof(value));
//
//  inout.close();
//
//  // Create a file
//  inout.open("city.dat", ios::in | ios::binary);
//  inout.write(reinterpret_cast < char * > (& value), sizeof(value));

    system("pause");
  return 0;
}
