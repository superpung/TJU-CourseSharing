#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  const int SIZE = 5;  // Array size

  fstream binaryio; // Create stream object

  // Write array to the file
  binaryio.open("array.dat", ios::out | ios::binary);
  double array[SIZE] = {3.4, 1.3, 2.5, 5.66, 6.9};
  binaryio.write(reinterpret_cast<char *>(&array), sizeof(array));
  binaryio.close();

  // Read array from the file
  binaryio.open("array.dat", ios::in | ios::binary);
  double result[SIZE];
  binaryio.read(reinterpret_cast<char *>(&result), sizeof(result));
  binaryio.close();

  // Display array
  for (int i = 0; i < SIZE; i++)
    cout << result[i] << " ";

    system("pause");
  return 0;
}
