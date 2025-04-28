#include <stdio.h>
#include <stdlib.h>

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to print inorder traversal
void Inorder(struct Node* Treenode) {
    if (Treenode == NULL)
        return;

    // First recur on left subtree
    Inorder(Treenode->left);

    // Now deal with the Treenode
    printf("%d ", Treenode->data);

    // Then recur on right subtree
    Inorder(Treenode->right);
}

// Function to create a new Treenode
struct Node* newNode(int v) {
    struct Node* Treenode = 
      (struct Node*)malloc(sizeof(struct Node));
    Treenode->data = v;
    Treenode->left = Treenode->right = NULL;
    return Treenode;
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Function call
    printf("Inorder traversal of binary tree is: \n");
    Inorder(root);

    return 0;
}
