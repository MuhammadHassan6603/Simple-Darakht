#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *left;
	int data;
	struct Node *right;	
};
void inOrder(struct Node *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%i",root->data);
		inOrder(root->right);
	}
}
void preOrder(struct Node *root)
{
	if(root!=NULL)
	{
		printf("%i",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(struct Node *root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%i",root->data);
	}
}
struct Node *create()
{
	struct Node *r;
	int data;
	printf("\nEnter Data: ");
	scanf("%i",&data);
	if(data==-1)
	{
		return;
	}
	r=(struct Node *)malloc(sizeof(struct Node));
	r->data=data;
	printf("\nEnter Left Child of %i",data);
	r->left=create();
	printf("\nEnter Right Child of %i",data);
	r->right=create();
	return r;
}
void main()
{
	struct Node *root;
	root=NULL;
	root=create();
	inOrder(root);
	printf("\n");
	preOrder(root);
	printf("\n");
	postOrder(root);
}
