#include <cstdlib>
using namespace std;

// Generate a random character between ch1 and ch2
char getRandomCharacter(char ch1, char ch2)
{
  return static_cast<char>(ch1 + std::rand() % (ch2 - ch1 + 1));
}

// Generate a random lowercase letter
char getRandomLowerCaseLetter()
{
  return getRandomCharacter('a', 'z');
}

// Generate a random uppercase letter
char getRandomUpperCaseLetter()
{
  return getRandomCharacter('A', 'Z');
}

// Generate a random digit character
char getRandomDigitCharacter()
{
  return getRandomCharacter('0', '9');
}

// Generate a random character
char getRandomCharacter()
{
  return getRandomCharacter(0, 127);
}
