#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream inout;

  // Create a file
  inout.open("city.txt", ios::out);

  // Write cities
  inout << "Dallas" << " " << "Houston" << " " << "Atlanta" << " ";

  inout.close();

  // Append to the file
  inout.open("city.txt", ios::out | ios::app);

  // Write cities
  inout << "Savannah" << " " << "Austin" << " " << "Chicago";

  inout.close();

  char city[20];

  // Open the file
  inout.open("city.txt", ios::in);
  while (!inout.eof()) // Continue if not end of file
  {
    inout >> city;
    cout << city << " ";
  }

  inout.close();

    system("pause");
  return 0;
}
