#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char s1[20] = "Dallas";
  char s2[20] = "Texas, USA";
  char s3[20] = "Dallas";

  strcat(strcat(s1, ", "), s2);
  strncat(strcat(s3, ", "), s2, 5);

  cout << "The string in s1 is " << s1 << endl;
  cout << "The string in s2 is " << s2 << endl;
  cout << "The string in s3 is " << s3 << endl;
  cout << "The length of string s1 is " << strlen(s1) << endl;
  cout << "The length of string s3 is " << strlen(s3) << endl;

    system("pause");
  return 0;
}
