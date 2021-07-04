#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

void printList(LinkedList<string> list)
{
  for (int i = 0; i < list.getSize(); i++)
  {
    cout << list.get(i) << " ";
  }
  cout << endl;
}

int main()
{
  // Create a list for strings
  LinkedList < string > list;

  // Add elements to the list
  list.add("America"); // Add it to the list
  cout << "(1) ";
  printList(list);

  list.add(0, "Canada"); // Add it to the beginning of the list
  cout << "(2) ";
  printList(list);

  list.add("Russia"); // Add it to the end of the list
  cout << "(3) ";
  printList(list);

  list.add("France"); // Add it to the end of the list
  cout << "(4) ";
  printList(list);

  list.add(2, "Germany"); // Add it to the list at index 2
  cout << "(5) ";
  printList(list);

  list.add(5, "Norway"); // Add it to the list at index 5
  cout << "(6) ";
  printList(list);

  list.add(0, "Netherlands"); // Same as list.addFirst("Netherlands")
  cout << "(7) ";
  printList(list);

  // Remove elements from the list
  list.removeAt(0); // Same as list.remove("Netherlands Australia") in this case
  cout << "(8) ";
  printList(list);

  list.removeAt(2); // Remove the element at index 2
  cout << "(9) ";
  printList(list);

  list.removeAt(list.getSize() - 1); // Remove the last element
  cout << "(10) ";
  printList(list);

    system("pause");
  return 0;
}

