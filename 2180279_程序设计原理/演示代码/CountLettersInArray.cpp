#include <iostream>
#include "RandomCharacter.h"
using namespace std;

const int NUMBER_OF_LETTERS = 100;
char * createArray();
void displayArray(char []);
int * countLetters(char []);
void displayCounts(int []);

int main()
{
  // Declare and create an array
  char * chars = createArray();

  // Display the array
  cout << "The lowercase letters are: " << endl;
  displayArray(chars);

  // Count the occurrences of each letter
  int * counts = countLetters(chars);

  // Display counts
  cout << endl;
  cout << "The occurrences of each letter are: " << endl;
  displayCounts(counts);

    system("pause");
  return 0;
}

// Create an array of characters
char * createArray()
{
  // Declare an array of characters and create it
  char *chars = new char[NUMBER_OF_LETTERS];

  // Create lowercase letters randomly and assign
  // them to the array
  srand(time(0));
  for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    chars[i] = getRandomLowerCaseLetter();

  // Return the array
  return chars;
}

// Display the array of characters
void displayArray(char chars[])
{
  // Display the characters in the array 20 on each line
  for (int i = 0; i < NUMBER_OF_LETTERS; i++)
  {
    if ((i + 1) % 20 == 0)
      cout << chars[i] << " " << endl;
    else
      cout << chars[i] << " ";
  }
}

// Count the occurrences of each letter
int * countLetters(char chars[])
{
  // Declare and create an array of 26 int
  int *counts = new int[26];

  // Initialize the array
  for (int i = 0; i < 26; i++)
    counts[i] = 0;

  // For each lowercase letter in the array, count it
  for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    counts[chars[i] - 'a'] ++;

  return counts;
}

// Display counts
void displayCounts(int counts[])
{
  for (int i = 0; i < 26; i++)
  {
    if ((i + 1) % 10 == 0)
      cout << counts[i] << " " << static_cast<char>(i + 'a') << endl;
    else
      cout << counts[i] << " " << static_cast<char>(i + 'a') << " ";
  }
}
