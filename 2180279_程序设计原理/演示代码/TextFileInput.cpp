#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream input;

  // Open a file
  input.open("scores.txt");

  // Read data
  char firstName[80];
  char mi;
  char lastName[80];
  int score;
  input >> firstName >> mi >> lastName >> score;
  cout << firstName << " " << mi << " " << lastName << " "
    << score << endl;

  input >> firstName >> mi >> lastName >> score;
  cout << firstName << " " << mi << " " << lastName << " "
    << score << endl;

  input.close();

  cout << "Done" << endl;
    system("pause");
  return 0;
}
