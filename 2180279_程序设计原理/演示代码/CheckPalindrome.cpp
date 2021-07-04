#include <iostream>
#include <cstring>
using namespace std;

// Check if a string is a palindrome
bool isPalindrome(const char *);

int main()
{
  // Prompt the user to enter a string
  cout << "Enter a string: ";
  char s[80];
  cin.getline(s, 80);

  if (isPalindrome(s))
    cout << s << " is a palindrome" << endl;
  else
    cout << s << " is not a palindrome" << endl;

    system("pause");
  return 0;
}

bool isPalindrome(const char * const s)
{
  // The index of the first character in the string
  int low = 0;

  // The index of the last character in the string
  int high = strlen(s) - 1;

  while (low < high)
  {
    if (s[low] != s[high])
      return false; // Not a palindrome

    low++;
    high--;
  }

  return true; // The string is a palindrome
}
