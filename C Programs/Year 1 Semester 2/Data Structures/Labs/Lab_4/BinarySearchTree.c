//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
	// write your code here
	if (*node == NULL)
	{
		*node = malloc(sizeof(BTNode));
		(*node)->item = value;
		(*node)->right = NULL;
		(*node)->left = NULL;
		return;
	}

	if (value < (*node)->item)
	{
		insertBSTNode(&((*node)->left), value);
	}
	else
	{
		insertBSTNode(&((*node)->right), value);
	}
	return;
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	// write your code here
	if (node == NULL)
		return;

	printBSTInOrder(node->left);
	printf("%d ", node->item);
	printBSTInOrder(node->right);
	return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	// write your code here

	if (node == NULL)
		return 1;

	if (node->item >= max || node->item <= min)
		return 0;

	return isBST(node->left, min, node->item) && isBST(node->right, node->item, max);

	// int l, r, check;

	// if (node->left == NULL && node->right == NULL)
	// {
	// 	return 1;
	// }

	// if (node->right != NULL && node->left != NULL)
	// {
	// 	l = isBST(node->left, min, max);
	// 	r = isBST(node->right, min, max);
	// 	min = node->left->item;
	// 	max = node->right->item;
	// 	if (node->item > min && node->item < max)
	// 	{
	// 		if (l==1 && r ==1)
	// 			return 1;
	// 	}
	// }

	// if (node->right == NULL && node->left != NULL)
	// {
	// 	l = isBST(node->left, min, max);
	// 	min = node->left->item;
	// 	if(node->item > min && l == 1)
	// 		return 1;
	// }
	
	// if (node->left == NULL && node->right != NULL)
	// {
	// 	r = isBST(node->right, min, max);
	// 	max = node->right->item;
	// 	if(node->item < max && r == 1)
	// 		return 1;
	//	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
	// write your code here
	BTNode *p;
	if (node == NULL)
	{
		printf("Can't find the value! \n");
		return NULL;
	}
	
	if (node->item > value) //go left tree
		node->left = removeBSTNode(node->left, value);

	if (node->item < value) //go right tree
		node->right = removeBSTNode(node->right, value);

	else //if ((*node)->item == value) found the node!
		if (node->left != NULL && node->right != NULL) //node has 2 children
		{
			p = findMin(node->right);
			node->item = p->item;
			node->right = removeBSTNode(node->right, p->item);
		}
		
		else //x has no children or 1 child
		{
			p = node;
			if (node->left != NULL)
				node = node->left;
			else
				node = node->right;

			free(p);
		}
	return node;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
	// write your code here
	// smallest number will always be on the left
	if (p->left != NULL)
	{
		return findMin(p->left);
	}

	else
		return p;

	// BTNode *l, *r;

	// if (p == NULL)
	// 	return NULL;

	// l = findMin(p->left);
	// r = findMin(p->right);

	// if (l->item < r->item)
	// {
	// 	if (l->item < p->item)
	// 		return l;
	// 	else
	// 		return p;
	// }
	// else
	// {
	// 	if (r->item < p->item)
	// 		return r;
	// 	else
	// 		return p;
	// }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////