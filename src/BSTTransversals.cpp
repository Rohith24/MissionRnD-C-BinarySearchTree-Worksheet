/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int getinorder(struct node *root, int *arr, int index){
	if (root != NULL)
	{
		index = getinorder(root->left, arr, index);
		arr[index] = root->data;
		index = getinorder(root->right, arr, index+1);
	}
	return index;
}

int getpreorder(struct node *root, int *arr, int index)
{
	if (root != NULL)
	{
		arr[index] = root->data;
		index=getpreorder(root->left, arr, index+1);
		index = getpreorder(root->right, arr, index);
	}
	return index;
}

int getpostorder(struct node *root, int *arr, int index)
{
	if (root != NULL)
	{
		index = getpostorder(root->left, arr, index);
		index = getpostorder(root->right, arr, index);
		arr[index++] = root->data;
	}
	return index;
}

void inorder(struct node *root, int *arr){
	if (arr!=NULL)
	getinorder(root, arr, 0);
}
void preorder(struct node *root, int *arr){
	if (arr != NULL)
	getpreorder(root, arr, 0);
}
void postorder(struct node *root, int *arr){
	if (arr != NULL)
	getpostorder(root, arr, 0);
}

