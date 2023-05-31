#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a node structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} node;

// Create a new node with a given data value and return its pointer
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append a new node with a given data value to the end of the linked list and return its pointer
node* appendNode(node* head, int data) {
    node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    return head;
}

// Print the data values of all the nodes in the linked list
void printList(node* head) {
    node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Free the memory allocated for the linked list
void freeList(node* head) {
    node* curr = head;
    while (curr != NULL) {
        node* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

// Generate N random numbers between P and Q and store them in a linked list
node* generateRandomNumToList(int N, int P, int Q) {
    node* head = NULL;

    srand(time(NULL)); // initialize random seed

    for (int i = 0; i < N; i++) {
        int num = rand() % (Q - P + 1) + P;
        head = appendNode(head, num);
    }

    return head;
}

// Write the data values of the linked list to a file
void writeListToFile(node* head, char* filename) {
    FILE *fp = fopen(filename, "w");

    node* curr = head;
    while (curr != NULL) {
        fprintf(fp, "%d ", curr->data);
        curr = curr->next;
    }

    fclose(fp);
}

int main() {
    int N, P, Q;
    char* filename = "Input.txt";

    printf("Enter the value of N: ");
    scanf("%d", &N);

    printf("Enter the value of P: ");
    scanf("%d", &P);

    printf("Enter the value of Q: ");
    scanf("%d", &Q);

    // Generate a linked list of random numbers
    node* head = generateRandomNumToList(N, P, Q);

    // Write the linked list to a file
    writeListToFile(head, filename);

    printf("%d random numbers between %d and %d have been generated and written to the file %s\n", N, P, Q, filename);

    // Print the linked list for verification
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
