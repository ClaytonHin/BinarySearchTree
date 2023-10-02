//Project: Binary Search Tree
//By: Clayton Hinderline
//Date: 8/13/2023
//No external sources used
#include "BST.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "Welcome to my BST Assignment..." << endl;
	//Create our class object to use our created methods
	BST bstObject1;
	TreeNode* root = NULL;
	//Hardcode a 15 to be included in the BST every time we create the tree
	bstObject1.add(15);

	//Generate 10 or more random numbers to be inserting into the BST
	srand(time(0));
	int num;
	for (int i = 0; i < 10; i++)
	{
		//Randomizes a number between 1 and 100
		num = 1 + (rand() % 100);
		//Adds the randomized number in our BST
		bstObject1.add(num);
	}
	//Print the BST out inorder
	bstObject1.inorder();

	//I'm not sure whats wrong with my remove function, however it is not currently working. I will fix this at a later time, as I need to move on for now.
	
	bstObject1.deleteNode(root, 15);
	bstObject1.inorder();

	//store our max in a variable to be printed using a cout statement
	int big = bstObject1.max();
	//Print out the maximum value
	cout << "\n\nMaxmimum value in the BST: " << big << endl;
	//Exit the program
	return 0;
}