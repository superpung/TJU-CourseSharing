#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream> 
using namespace std; 
template<typename T>
class TreeNode
{
public:
  T element; // Element contained in the node
  TreeNode<T> * left; // Pointer to the left child
  TreeNode<T> * right; // Pointer to the right child

  TreeNode() // No-arg constructor
  {
    left = NULL;
    right = NULL;
  }

  TreeNode(T element) // Constructor
  {
    this->element = element;
    left = NULL;
    right = NULL;
  }
};

template < typename T >
class BinaryTree
{
public:
  BinaryTree();
  BinaryTree(T elements[]);
  bool insert(T element);
  void inorder();
  void preorder();
  void postorder();
  int getSize();

private:
  TreeNode<T> * root;
  int size;
  void inorder(TreeNode<T> *root);
  void postorder(TreeNode<T> *root);
  void preorder(TreeNode<T> *root);
};

template < typename T >
BinaryTree<T>::BinaryTree()
{
  root = NULL;
  size = 0;
}

/* Insert element o into the binary tree
 * Return true if the element is inserted successfully
 * Return false if the element is already in the list
 */
template <typename T>
bool BinaryTree<T>::insert(T element)
{
  if (root == NULL)
    root = new TreeNode<T>(element); // Create a new root
  else
  {
    // Locate the parent node
    TreeNode<T> *parent = NULL;
    TreeNode<T> *current = root;
    while (current != NULL)
      if (element < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (element > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        return false; // Duplicate node not inserted

    // Create the new node and attach it to the parent node
    if (element < parent->element)
      parent->left = new TreeNode<T>(element);
    else
      parent->right = new TreeNode<T>(element);
  }

  size++;
  return true; // Element inserted
}

/* Inorder traversal */
template <typename T>
void BinaryTree<T>::inorder()
{
  inorder(root);
}

/* Inorder traversal from a subtree */
template <typename T>
void BinaryTree<T>::inorder(TreeNode<T> *root)
{
  if (root == NULL) return;
  inorder(root->left);
  cout << root->element << " ";
  inorder(root->right);
}

/* Postorder traversal */
template <typename T>
void BinaryTree<T>::postorder()
{
  postorder(root);
}

/** Inorder traversal from a subtree */
template <typename T>
void BinaryTree<T>::postorder(TreeNode<T> *root)
{
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->element << " ";
}

/* Preorder traversal */
template <typename T>
void BinaryTree<T>::preorder()
{
  preorder(root);
}

/* Preorder traversal from a subtree */
template <typename T>
void BinaryTree<T>::preorder(TreeNode<T> *root)
{
  if (root == NULL) return;
  cout << root->element << " ";
  preorder(root->left);
  preorder(root->right);
}

/* Get the number of nodes in the tree */
template <typename T>
int BinaryTree<T>::getSize()
{
  return size;
}

#endif
