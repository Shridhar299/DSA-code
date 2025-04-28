// C program to find the height of a binary 
// tree using depth-first search (DFS) approach.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}; 

// Returns "height" which is the number of edges 
// along the longest path from the root node down 
// to the farthest leaf node.
int height(struct Node* root) {
    if (root == NULL)
        return -1;

    // compute the height of left and right subtrees
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return (lHeight > rHeight ? lHeight : rHeight) + 1;
}

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
  
    // Representation of the input tree:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    printf("%d\n", height(root));
    
    return 0;
}
