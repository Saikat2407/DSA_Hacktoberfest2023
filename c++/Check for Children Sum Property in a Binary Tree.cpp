/* Program to check children sum property */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, left
child and right child */
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* returns 1 if children sum property holds
for the given node and both of its children*/
int isSumProperty(struct node* node)
{
	/* left_data is left child data and
	right_data is for right child data*/
	int sum = 0;

	/* If node is NULL or it's a leaf node
	then return true */
	if (node == NULL
		|| (node->left == NULL && node->right == NULL))
		return 1;
	else {
		/* If left child is not present then 0
		is used as data of left child */
		if (node->left != NULL)
			sum += node->left->data;

		/* If right child is not present then 0
		is used as data of right child */
		if (node->right != NULL)
			sum += node->right->data;

		/* if the node and both of its children
		satisfy the property return 1 else 0*/
		return ((node->data == sum)
				&& isSumProperty(node->left)
				&& isSumProperty(node->right));
	}
}

/*
Helper function that allocates a new node
with the given data and NULL left and right
pointers.
*/
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// Driver Code
int main()
{
	struct node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->right = newNode(2);

	// Function call
	if (isSumProperty(root))
		cout << "The given tree satisfies "
			<< "the children sum property ";
	else
		cout << "The given tree does not satisfy "
			<< "the children sum property ";

	getchar();
	return 0;
}
// This code is contributed by Akanksha Rai
