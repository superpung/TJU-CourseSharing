#include <iostream>
#include <cstring>
#include "Substring.h"
using namespace std;

bool isPalindrome(const char * const s)
{
  if (strlen(s) <= 1) // Base case
    return true;
  else if (s[0] != s[strlen(s) - 1]) // Base case
    return false;
  else
    return isPalindrome(substring(s, 1, strlen(s) - 1));
}

int main()
{
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

