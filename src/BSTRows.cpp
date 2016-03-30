/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
typedef struct node bstree;
struct queuenode
{
	bstree *d;
	struct queuenode *next;
};

struct queuenode* makenullqueue()
{
	struct queuenode* q;
	q = (struct queuenode*)malloc(sizeof(struct queuenode));
	q->d = NULL;
	q->next = NULL;
	return q;
}

void enqueue(struct queuenode * q, struct node *e)
{
	struct queuenode * p = q, *r;
	while (p->next != NULL)
		p = p->next;
	r = makenullqueue();
	r->d = e;
	p->next = r;
}

struct node * dequeue(struct queuenode * q){
	struct queuenode *p = q, *r;
	struct node *e = q->next->d;
	r = p->next;
	p->next = r->next;
	free(r);
	return e;
}

int empty(struct queuenode * q)
{
	if (q->next == NULL)
		return 1;
	return 0;
}
int get_no_of_nodes(struct node *root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + get_no_of_nodes(root->left) + get_no_of_nodes(root->right);
}
int * printLevel(struct node* root)
{
	struct queuenode *queue = makenullqueue();
	enqueue(queue, root);
	int *result = (int *)malloc(sizeof(int)*get_no_of_nodes(root));
	int index = 0;
	while (!empty(queue))
	{
		struct node *temp = dequeue(queue);

		result[index++] = temp->data;
		if (temp->right){ 
			enqueue(queue,temp->right); 
		}
		if (temp->left){
			enqueue(queue, temp->left);
		}
	}
	return result;
}

int * BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int index = 0;
	int *arr;
	arr=printLevel(root);
	return arr;
}
