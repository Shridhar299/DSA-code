#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void bubbleSort(Node* head, int x) {
    Node* temp;
    int i, j;
    for(i = 0; i < x - 1; i++) {
        for(j = 0, temp = head; j < x - i - 1; j++, temp = temp->next) {
            if(temp->data > temp->next->data) {
                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
        }
    }
}

void selectionSort(Node* head, int x) {
    Node* i, *j, *min;
    int t;
    for(i = head; i->next != NULL; i = i->next) {
        min = i;
        for(j = i->next; j != NULL; j = j->next) {
            if(j->data < min->data) {
                min = j;
            }
        }
        t = i->data;
        i->data = min->data;
        min->data = t;
    }
}

void insertionSort(Node* head, int x) {
    Node *i, *j;
    int key;
    for(i = head->next; i != NULL; i = i->next) {
        key = i->data;
        for(j = i->next; j != NULL && j->data > key; j = j->next) {
            j->prev->data = j->data;
        }
        j->prev->data = key;
    }
}

int main() {
    FILE *input_file, *log_file;
    Node *head = NULL, *temp, *prev;
    int x, i, choice;

    // Open input file for reading
    input_file = fopen("Input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file!");
        return 1;
    }

    // Open log file for writing
    log_file = fopen("log.txt", "w");
    if (log_file == NULL) {
        printf("Error opening log file!");
        return 1;
    }

    // Read the value of X from user
    printf("Enter the value of X: ");
    scanf("%d", &x);

    // Read X elements from input file and create linked list
    for (i = 0; i < x; i++) {
        temp = (Node*) malloc(sizeof(Node));
        fscanf(input_file, "%d", &(temp->data));
        temp->next = NULL;
        if(head == NULL) {
            head = temp;
            head->prev = NULL;
        } else {
            prev->next = temp;
            temp->prev = prev;
        }
        prev = temp;
    }


    printf("3. Bubble Sort\n");
    printf("4. Selection Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    clock_t start, end;
    double cpu_time_used;
    switch(choice) {
        case 1:
            start = clock();
            insertionSort(head, x);
            end = clock();
            cpu_time_used = ((double) (
