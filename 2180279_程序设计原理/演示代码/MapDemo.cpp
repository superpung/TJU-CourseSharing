#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
  map<int, string> map1;
  map1.insert(map<int, string>::value_type(100, "John Smith"));
  map1.insert(map<int, string>::value_type(101, "Peter King"));
  map1.insert(map<int, string>::value_type(102, "Jane Smith"));
  map1.insert(map<int, string>::value_type(103, "Jeff Reed"));

  cout << "Initial contents in map1:\n";
  map<int, string>::iterator p;
  for (p = map1.begin(); p != map1.end(); p++)
    cout << p->first << " " << p->second << endl;

  cout << "Enter a key to serach for the name: ";
  int key;
  cin >> key;
  p = map1.find(key);

  if (p == map1.end())
    cout << "  Key " << key << " not found in map1";
  else
    cout << "  " << p->first << " " << p->second << endl;

  map1.erase(103);
  cout << "\nAfter the erase function, map1:\n";
  for (p = map1.begin(); p != map1.end(); p++)
    cout << p->first << " " << p->second << endl;

    system("pause");
  return 0;
}
