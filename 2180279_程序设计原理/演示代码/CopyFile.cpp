#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  const int FILENAME_SIZE = 40;

  // Enter a source file
  cout << "Enter a source file name: ";
  char inputFilename[FILENAME_SIZE];
  cin >> inputFilename;

  // Enter a target file
  cout << "Enter a target file name: ";
  char outputFilename[FILENAME_SIZE];
  cin >> outputFilename;

  ifstream input;
  ofstream output;

  // Open a file
  input.open(inputFilename);
  output.open(outputFilename);

  if (input.fail())
  {
    cout << inputFilename << " does not exist" << endl;
    cout << "Exit program" << endl;
    system("pause");
    return 0;
  }

  while (!input.eof()) // Continue if not end of file
  {
    output.put(input.get());
  }

  input.close();
  output.close();

  cout << "\nCopy Done" << endl;

    system("pause");
  return 0;
}
