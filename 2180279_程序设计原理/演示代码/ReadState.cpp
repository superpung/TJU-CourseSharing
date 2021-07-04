#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream input;

  // Open a file
  input.open("state.txt");

  if (input.fail())
  {
    cout << "File does not exist" << endl;
    cout << "Exit program" << endl;
    system("pause");
    return 0;
  }

  // Read data
  char state[40];

  while (!input.eof()) // Continue if not end of file
  {
    input.getline(state, 40, '#');
    cout << state << endl;
  }

  input.close();

  cout << "Done" << endl;
    system("pause");
  return 0;
}
