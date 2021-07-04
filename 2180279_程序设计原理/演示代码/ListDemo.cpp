#include <iostream>
#include <list>
using namespace std;

int main()
{
  int values[] = {1, 2, 3, 4 };
  list<int> intList(values, values + 4);

  cout << "Initial contents in intList: ";
  list<int>::iterator p;
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  intList.assign(4, 11);
  cout << "\nAfter the assign function, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  list<int>::iterator itr = intList.begin();
  itr++;
  intList.insert(itr, 555);
  intList.insert(itr, 666);
  cout << "\nAfter the insert function, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  list<int>::iterator beg = intList.begin();
  itr++;
  intList.erase(beg, itr);
  cout << "\nAfter the erase function, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  intList.clear();
  cout << "\nAfter the clear function, intList: ";
  cout << "Size is " << intList.size() << endl;
  cout << "Is empty? " <<
        (intList.empty() ? "true" : "false");

  intList.push_front(10);
  intList.push_front(11);
  intList.push_front(12);
  cout << "\nAfter the push functions, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  intList.pop_front();
  intList.pop_back();
  cout << "\nAfter the pop functions, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  int values1[] = {7, 3, 1, 2};
  list<int> list1(values1, values1 + 4);
  list1.sort();
  cout << "\nAfter the sort function, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  list<int> list2(list1);
  list1.merge(list2);
  cout << "\nAfter the merge function, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";
  cout << "\nSize of list2 is " << list2.size();

  list1.reverse();
  cout << "\nAfter the reverse function, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  list1.push_back(7);
  list1.push_back(1);
  cout << "\nAfter the push functions, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  list1.remove(7);
  cout << "\nAfter the remove function, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  list2.assign(7, 2);
  cout << "\nAfter the assign function, list2: ";
  for (p = list2.begin(); p != list2.end(); p++)
    cout << *p << " ";

  p = list2.begin();
  p++;
  list2.splice(p, list1);
  cout << "\nAfter the splice function, list2: ";
  for (p = list2.begin(); p != list2.end(); p++)
    cout << *p << " ";
  cout << "\nAfter the splice function, list1’s size is "
    << list1.size();

    system("pause");
  return 0;
}
