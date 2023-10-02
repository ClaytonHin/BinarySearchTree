#pragma once
//Structure is just a class without methods
struct TreeNode
{
	//Our data
	int item;
	//Pointers for the left and right child
	TreeNode* Lchild;
	TreeNode* Rchild;
};

//Create a BST class so we can create methods to use our Binary Search Tree
class BST
{
public:
	//Constructor
	BST();
	//Create a add method to input data into our BST, this will take a interger however it can be strings aswell.
	bool add(int i);
	//Create a remove method to remove a certain number from our BST. This takes the interger you want to remove as the parameter
	TreeNode* deleteNode(TreeNode* root, int k);
	//Create a way to print our BST in order
	void inorder();
	//Create a way to print the maximum value in our BST
	int max();
	TreeNode* getRoot();

	//Create a pointer for our root node. This will be the node at the very top of the tree
	TreeNode* root;
	//Create a helper function
	void inorder(TreeNode*);
};