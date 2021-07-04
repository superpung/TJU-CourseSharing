#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char *s1 = "abcdefg";
  char *s2 = "abcdg";
  char *s3 = "abcdg";

  cout << "strcmp(s1, s2) is " << strcmp(s1, s2) << endl;
  cout << "strcmp(s2, s1) is " << strcmp(s2, s1) << endl;
  cout << "strcmp(s2, s3) is " << strcmp(s2, s3) << endl;
  cout << "strncmp(s1, s2, 3) is " << strncmp(s1, s2, 3) << endl;

    system("pause");
  return 0;
}
