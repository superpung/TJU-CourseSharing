#include <iostream>
#include <fstream>
using namespace std;

void showState(fstream &);

int main()
{
  fstream inout;

  // Create an output file
  inout.open("temp.txt", ios::out);
  inout << "Dallas";
  cout << "Normal operation (no errors)" << endl;
  showState(inout);
  inout.close();

  // Create an output file
  inout.open("temp.txt", ios::in);

  // Read a string
  char city[6];
  inout >> city;
  cout << "End of file (no errors)" << endl;
  showState(inout);

  inout.close();

  // Attempt to read after file closed
  inout >> city;
  cout << "Bad operation (errors)" << endl;
  showState(inout);

    system("pause");
  return 0;
}

void showState(fstream & stream)
{
  cout << "Stream status: " << endl;
  cout << "  eof(): " << stream.eof() << endl;
  cout << "  fail(): " << stream.fail() << endl;
  cout << "  bad(): " << stream.bad() << endl;
  cout << "  good(): " << stream.good() << endl;
}
