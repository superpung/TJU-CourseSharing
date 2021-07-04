#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char s1[20];
  char s2[20] = "Dallas, Texas";
  char s3[20] = "AAAAAAAAAA";

  strcpy(s1, s2);
  strncpy(s3, s2, 6);
  s3[6] = '\0'; // Insert null terminator

  cout << "The string in s1 is " << s1 << endl;
  cout << "The string in s2 is " << s2 << endl;
  cout << "The string in s3 is " << s3 << endl;
  cout << "The length of string s3 is " << strlen(s3) << endl;

    system("pause");
  return 0;
}
