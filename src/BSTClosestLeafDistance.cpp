/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int getmindistance(struct node *root)
{
	int minleft, minright;
	if ((root->left == NULL && root->right == NULL) || root == NULL)
		return 0;
	else if (root->left == NULL && root->right != NULL)
		return 1 + getmindistance(root->right);
	else if (root->right == NULL && root->left != NULL)
		return 1 + getmindistance(root->left);
	else
	{
		minleft = getmindistance(root->right);
		minright = getmindistance(root->left);
		return 1 + min(minright, minleft);
	}
}

int get_closest_leaf_distance_rec(struct node *root, struct node *temp, int mindis)
{
	int currmin;
	currmin= min(getmindistance(root), mindis);
	if (root == temp)
		return currmin;
	else if (root->data<temp->data)
		return get_closest_leaf_distance_rec(root->right, temp, currmin + 1);
	else
		return get_closest_leaf_distance_rec(root->left, temp, currmin + 1);
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	int result, min_distance;
	min_distance = getmindistance(root);
	result = get_closest_leaf_distance_rec(root, temp, min_distance);
	return result;
}