/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void get_misplaced(struct node *root, int *a, int *b){
	if (root->left != NULL){
		if (root->data > root->left->data){
			get_misplaced(root->left, a, b);
		}
		else
		{
			*a = root->left->data;
			if (root->data < *b){
				*b = root->data;
			}
		}
	}
	if (root->right != NULL){
		if (root->data < root->right->data){
			get_misplaced(root->right, a, b);
		}
		else
		{
			*b = root->right->data;
			if (root->data>*a){
				*a = root->data;
			}
		}
	}

}

void swap_misplaced(struct node *root, int a, int b, int achanged, int bchanged){
	if (root != NULL){
		if (root->data == a && achanged == 0) {
			root->data = b;
			achanged = 1;
		}
		else if (root->data == b && bchanged == 0)
		{
			root->data = a;
			bchanged = 1;
		}
		swap_misplaced(root->left, a, b, achanged, bchanged);
		swap_misplaced(root->right, a, b, achanged, bchanged);
	}
}

void fix_bst(struct node *root){
	int a = 0, b = 999;
	if (root != NULL)
		get_misplaced(root, &a, &b);
	swap_misplaced(root, a, b,0,0);
	int c = 0;
}
