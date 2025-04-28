#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Define the structure for the stack
struct stack {
    struct Node *top;
};

// Function to push an element onto the stack
void push(struct stack *sptr, int num);

// Function to pop an element from the stack
void pop(struct stack *sptr);

// Function to display the stack
void display(struct stack *sptr);

// Function to peek the top element of the stack
void peek(struct stack *sptr);

int main() {
    struct stack s;
    struct stack *sptr;
    sptr=&s;
    s.top = NULL;  // Initialize top to NULL
    int num, ch;

    while(1) {
        printf("Enter the choice\n");
        printf("1: push elements\n2: pop elements\n3: peek elements\n4: display stack\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value: ");
				scanf("%d", &num);
                push(&s, num);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                printf("\n");
                break;
            case 4:
                display(&s);
                break;
            case -1:
                exit(0);
            default:
                printf("Enter valid choice\n");
                break;
        }
    }
    return 0;
}

// Function to push an element onto the stack
void push(struct stack *sptr, int num) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = num;
    newNode->next = sptr->top;
    sptr->top = newNode;
}

// Function to pop an element from the stack
void pop(struct stack *sptr) {
    if (sptr->top == NULL) {
        printf("Stack underflow\n");
    } else {
        struct Node *temp = sptr->top;
        int num = temp->data;
        sptr->top = sptr->top->next;
        free(temp);
        printf("%d \n", num);
    }
}

// Function to peek the top element of the stack
void peek(struct stack *sptr) {
    if (sptr->top == NULL) {
        printf("Stack empty\n");
    } else {
        printf("%d", sptr->top->data);
    }
}

// Function to display the stack
void display(struct stack *sptr) {
    struct Node *temp = sptr->top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

