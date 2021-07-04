#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(const char * const s, int low, int high)
{
  if (high <= low) // Base case
    return true;
  else if (s[low] != s[high]) // Base case
    return false;
  else
    return isPalindrome(s, low + 1, high - 1);
}

bool isPalindrome(const char * const s)
{
  return isPalindrome(s, 0, strlen(s) - 1);
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
