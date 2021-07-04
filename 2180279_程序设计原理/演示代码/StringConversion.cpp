#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  cout << atoi("4") + atoi("5") << endl;
  cout << atof("4.5") + atof("5.5") << endl;

  char s[10];
  itoa(42, s, 8);
  cout << s << endl;

  itoa(42, s, 10);
  cout << s << endl;

  itoa(42, s, 16);
  cout << s << endl;

    system("pause");
  return 0;
}
