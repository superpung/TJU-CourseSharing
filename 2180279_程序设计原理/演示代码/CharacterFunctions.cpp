#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a character: ";
  char ch;
  cin >> ch;

  cout << "You entered " << ch << endl;

  if (islower(ch)) {
    cout << "It is a lowercase letter " << endl;
    cout << "Its equivalent uppercase letter is " <<
      static_cast<char>(toupper(ch)) << endl;
  }
  else if (isupper(ch)) {
      cout << "It is an uppercase letter " << endl;
      cout << "Its equivalent lowercase letter is " <<
        static_cast<char>(tolower(ch)) << endl;
  }
  else if (isdigit(ch)) {
      cout << "It is a digit character " << endl;
  }

    system("pause");
  return 0;
}
