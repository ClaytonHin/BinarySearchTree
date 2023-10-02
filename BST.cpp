#include "BST.h"
#include <iostream>
using namespace std;

//Define our constructor
BST::BST()
{
	//Declare that there is no data that exists within our BST
	root = NULL;
}

//Define our add method
bool BST::add(int i)
{
	//Create our tree node
	TreeNode* n = new TreeNode();
	//Put our number/data into the created node
	n->item = i;
	//Check if the tree is empty, if so this new node will be our root node
	if (root == NULL)
	{
		//Set our data to our root node
		root = n;
		//Return that we have successfully added a node to our BST
		return true;
	}
	else
	{
		//Create a tree node that can move throughout the BST to find the correct postition for the added number. This will always start from the root node
		TreeNode* current = root;
		//While loop that will end if we reach the bottom of the tree. Which would be NULL since there is no data left in the BST
		while (current != NULL)
		{
			//Create a if statement to check if there is any duplicate values in the BST
			if (i == current->item)
			{
				//reuturn false, since we failed to add our data since it already existed in our BST
				return false;
			}
			//Decide which direction the data should move depending on its size compared to the root node. We are using int so this will be easy to understand
			//If the value is less than the current nodes value
			else if (i < current->item)
			{
				//Go to the left subtree
				if (current->Lchild == NULL)
				{
					current->Lchild = n;
					return true;
				}
				else
				{
					current = current->Lchild;
				}
			}
			else
			{
				//Go to the right subtree, since the value being inserted is greater than our root nodes value
				if (current->Rchild == NULL)
				{
					current->Rchild = n;
					return true;
				}
				else
				{
					current = current->Rchild;
				}
			}
		}
	}
	return false;
}
//Define our delete node method
TreeNode* BST::deleteNode(TreeNode* root, int k)
{
	//This will be our base case
	if (root == NULL)
	{
		return root;
	}
	//Recursive calls for ancestors of our node to be deleted
	if (root->item > k)
	{
		root->Lchild = deleteNode(root->Lchild, k);
		return root;
	}
	else if (root->item < k)
	{
		root->Rchild = deleteNode(root->Rchild, k);
		return root;
	}

	//We will only do this if the root node is going to be deleted

	//If one of the childeren is empty
	if (root->Lchild == NULL)
	{
		TreeNode* temp = root->Rchild;
		//Free the memory space for our root
		delete root;
		//Our temp will be our new root
		return temp;
	}
	else if (root->Rchild == NULL)
	{
		//Same process as above
		TreeNode* temp = root->Lchild;
		delete root;
		return temp;
	}
	//If both childeren exists
	else
	{
		TreeNode* succParent = root;

		//Find the successor of the two childeren to be deleted. The successor is always the lesser value of the two childeren
		TreeNode* succ = root->Rchild;
		//While there is a left child of the successor
		while (succ->Lchild != NULL)
		{
			succParent = succ;
			succ = succ->Lchild;
		}

		//Now delete the succcessor
		if (succParent != root)
		{
			succParent->Lchild = succ->Rchild;
		}
		else
		{
			succParent->Rchild = succ->Rchild;
		}

		//Copy the successors data into our root node
		root->item = succ->item;

		//Delete our successor and return our root value
		delete succ;
		return root;
	}
}



//Define our inorder print method
void BST::inorder(TreeNode* n)
{
	//Check if there is even any data to be printed, if not then exit the print function
	if (n == NULL)
	{
		return;
	}
	//Start with our root and traverse as far left as you can. find the far most bottom value and take that node data and the node above its data and store them
	inorder(n->Lchild);
	//Go up a node and print the values
	cout << n->item << " ";
	//Go back and traverse as far right as you can
	inorder(n->Rchild);
}
//
void BST::inorder()
{
	inorder(root);
	cout << endl;
}
//Simple method that will return the root value
TreeNode* BST::getRoot()
{
	return root;
}
//Define our max function that will get the largest value in our BST
int BST::max()
{
	//Check if there is any value in our root, if there is none then exit 
	if (root == NULL)
	{
		cout << "Empty Tree..." << endl;
		return 0;
	}
	//If we have a root node
	else
	{
		//Create a node to traverse our tree that will start at our root
		TreeNode* current = root;
		//while loop to go right until the right pointer is NULL, meaning there are no larger values than our current node
		while (current->Rchild != NULL)
		{
			//Move our current pointer to the right child
			current = current->Rchild;

		}
		return current->item;
	}
}