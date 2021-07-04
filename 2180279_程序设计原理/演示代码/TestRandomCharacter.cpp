#include <iostream>
#include "RandomCharacter.h"
using namespace std;

int main()
{
  const int NUMBER_OF_CHARS = 175;
  const int CHARS_PER_LINE = 25;

  srand(time(0)); // Set a new seed for random function

  // Print random characters between '!' and '~', 25 chars per line
  for (int i = 0; i < NUMBER_OF_CHARS; i++)
  {
    char ch = getRandomLowerCaseLetter();
    if ((i + 1) % CHARS_PER_LINE == 0)
      cout << ch << endl;
    else
      cout << ch;
  }

    system("pause");
  return 0;
}
