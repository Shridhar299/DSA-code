#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) { return (q->front == NULL); }

// Function to add an element to the queue (Enqueue operation)
void enqueue(Queue* q, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

// Function to remove an element from the queue (Dequeue operation)
void dequeue(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

// Function to get the element at the front of the queue (Peek operation)
int peek(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; // return some default value or handle error differently
    }
    return q->front->data;
}

// Function to print the current queue
void printQueue(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Node* current = q->front;
    printf("Current Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Queue q;
    initializeQueue(&q);
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                printf("Front element: %d\n", peek(&q));
                break;

            case 4:
                printQueue(&q);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}