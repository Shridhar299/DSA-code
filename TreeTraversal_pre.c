#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void insertChild(Node* parent, Node* child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        Node* sibling = parent->firstChild;
        while (sibling->nextSibling != NULL) {
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = child;
    }
}

void preOrderTraversal(Node* node, int depth) {
    if (node == NULL) {
        return;
    }
    int i;
    for (i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("%s\n", node->name);

    preOrderTraversal(node->firstChild, depth + 1);

    preOrderTraversal(node->nextSibling, depth);
}

Node* buildFileSystem() {
    int numDirs;
    printf("Enter the number of directories: ");
    scanf("%d", &numDirs);

    Node* root = NULL;
   int i;
    for ( i = 0; i < numDirs; i++) {
        char name[100];
        printf("Enter the name of directory %d: ", i + 1);
        scanf(" %[^\n]", name);

        Node* newNode = createNode(name);

        if (root == NULL) {
            root = newNode;
        } else {
            char parentName[100];
            printf("Enter the name of the parent directory: ");
            scanf(" %[^\n]", parentName);

            Node* parentNode = root;
            Node* prevSibling = NULL;
            Node* sibling = root;

            while (sibling != NULL && strcmp(sibling->name, parentName) != 0) {
                prevSibling = sibling;
                sibling = sibling->nextSibling;
            }

            if (sibling == NULL) {
                printf("Parent directory not found. Creating directory %s as a child of the root.\n", name);
                insertChild(root, newNode);
            } else {
                if (prevSibling == NULL) {
                    parentNode->firstChild = newNode;
                } else {
                    prevSibling->nextSibling = newNode;
                }

                newNode->nextSibling = sibling->nextSibling;
                sibling->nextSibling = newNode;
            }
        }
    }

    return root;
}

int main() {
    Node* root = buildFileSystem();


    printf("Pre-order traversal of the file system:\n");
    preOrderTraversal(root, 0);

    return 0;
}
