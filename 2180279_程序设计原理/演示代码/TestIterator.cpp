#include <iostream>
#include <string>
#include "NewLinkedList.h"
using namespace std;

int main()
{
  // Create a list for strings
  LinkedList<string> list;

  // Add elements to the list
  list.add("America");
  list.add("Canada");
  list.add("Russia");
  list.add("France");

  // Traverse a list using iterators
  for (Iterator<string> iterator = list.begin();
    iterator != list.end(); iterator++)
  {
    cout << *iterator << " ";
  }

    system("pause");
  return 0;
}
