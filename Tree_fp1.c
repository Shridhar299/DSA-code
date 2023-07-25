#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to get the height of a node
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new AVL tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to right rotate subtree rooted with y
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to left rotate subtree rooted with x
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to get the balance factor of a node
int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Duplicate keys are not allowed
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to find the minimum value node in a given AVL tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Find the leftmost leaf node
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from the AVL tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node to be deleted found

        // Case 1: Node with no child or only one child
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else // One child case
                *root = *temp;

            free(temp);
        } else {
            // Case 2: Node with two children
            struct Node* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to find the median of the AVL tree
double findMedian(struct Node* node) {
    if (node == NULL)
        return 0;

    int totalNodes = 0;
    struct Node* current = node;

    // Count the total number of nodes
    while (current != NULL) {
        if (current->left == NULL) {
            totalNodes++;
            current = current->right;
        } else {
            struct Node* pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;
                totalNodes++;
                current = current->right;
            }
        }
    }

    int medianIndex = (totalNodes + 1) / 2;
    int count = 0;

    current = node;
    while (current != NULL) {
        if (current->left == NULL) {
            count++;
            if (count == medianIndex)
                return current->data;
            current = current->right;
        } else {
            struct Node* pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;
                count++;
                if (count == medianIndex)
                    return current->data;
                current = current->right;
            }
        }
    }

    return 0; // This line should never be reached
}

// Driver program to test above functions
int main() {
    struct Node* root = NULL;
    int numElements;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &numElements);

    int i, data;
    printf("Enter the data:\n");
    for (i = 0; i < numElements; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
while(1){
    int ch;
    printf("Enter your choice:\n1. Find the median\n2. Delete a node\n3. Find the median after deletion\n");
    scanf("%d", &ch);

    switch (ch) {
        case 1: {
            // Find the median
            double median = findMedian(root);
            printf("Median: %.2f\n", median);
            break;
        }
        case 2: {
            // Delete a node
            int deleteData;
            printf("Enter the element to delete: ");
            scanf("%d", &deleteData);
            root = deleteNode(root, deleteData);
            break;
        }
        case 3: {
            // Find the median after deletion
            double median = findMedian(root);
            printf("Median after deletion: %.2f\n", median);
            break;
        }
        default:
            printf("Invalid choice\n");
            break;
    }
}



    return 0;
}
