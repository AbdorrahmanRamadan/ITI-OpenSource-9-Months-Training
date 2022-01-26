#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

struct node* createNode(int item);
struct node* insertNode(struct node* node, int data);
void printInorder(struct node* root);
void printPreorder(struct node* root);
void printPostorder(struct node* root);

int main()
{
	struct node* root = NULL;
	root = insertNode(root, 15);
	insertNode(root, 13);
	insertNode(root, 12);
	insertNode(root, 41);
	insertNode(root, 17);
	insertNode(root, 61);
	insertNode(root, 18);

    printf("inorder : ");
	printInorder(root);
	printf("\n");
	printf("preorder : ");
	printPreorder(root);
	printf("\n");
	printf("postorder : ");
	printPostorder(root);

	return 0;
}

struct node* createNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void printInorder(struct node* root)
{
	if (root != NULL) {
		printInorder(root->left);
		printf("%d ", root->data);
		printInorder(root->right);
	}
}
void printPreorder(struct node* root)
{
	if (root != NULL) {
        printf("%d ", root->data);
		printPreorder(root->left);
		printPreorder(root->right);
	}
}
void printPostorder(struct node* root)
{
	if (root != NULL) {
		printPostorder(root->left);
        printPostorder(root->right);
		printf("%d ", root->data);
	}
}

struct node* insertNode(struct node* node, int data)
{
	if (node == 0)
		return createNode(data);

	if (data < node->data)
		node->left = insertNode(node->left, data);

	else if (data > node->data)
		node->right = insertNode(node->right, data);

	return node;
}
