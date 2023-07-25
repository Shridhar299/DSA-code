#include<stdio.h>

struct node {
	int key;
	struct node *left, *right;
};


struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d->", root->key);
		inorder(root->right);
	}
}


struct node* insert(struct node* node, int key)
{

	if (node == NULL)
		return newNode(key);


	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);


	return node;
}

int main()
{
    int key,no,ch;
	struct node* root = NULL;

	while(1)
   {
     printf("\n");
     printf("1) Insert Data\n");
     printf("2) Exit\n");


     printf("Enter your choice: ");
     scanf("%d",&ch);
     switch(ch)
     {

    case 1: printf("Enter the DATA of node: ");
            scanf("%d",&key);
            root = insert(root, key);
            printf("\nLatest Inorder traversal of the given tree \n");
            inorder(root);
            break;

    case 2: exit(0);break;
    default: printf("Invalid choice\n");
     }
   }
}
