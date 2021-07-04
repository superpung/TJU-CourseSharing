#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
  ofstream output;

  // Create a file
  output.open("formattedscores.txt");

  // Write two lines
  // Write two lines
  output << setw(6) << "John" << setw(2) << "T" << setw(6) << "Smith"
    << " " << setw(4) << 90 << endl;
  output << setw(6) << "Eric" << setw(2) << "K" << setw(6) << "Jones"
<< " " << setw(4) << 85;

  output.close();

  cout << "Done" << endl;
    system("pause");
  return 0;
}
