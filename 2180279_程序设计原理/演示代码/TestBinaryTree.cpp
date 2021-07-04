#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

int main()
{
  BinaryTree<string> tree;
  tree.insert("George");
  tree.insert("Michael");
  tree.insert("Tom");
  tree.insert("Adam");
  tree.insert("Jones");
  tree.insert("Peter");
  tree.insert("Daniel");

  cout << "Inorder (sorted): ";
  tree.inorder();

  cout << "\nPostorder: ";
  tree.postorder();

  cout << "\nPreorder: ";
  tree.preorder();

  cout << "\nThe number of nodes is " << tree.getSize();

    system("pause");
  return 0;
}
