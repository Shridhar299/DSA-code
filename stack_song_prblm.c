#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[20];
    int age;
    int rank;
    struct node *next;
};

struct node *top; // Pointer to the top of the stack

void push(struct node *);
void pop();
void display();
void search_by_age();

int main()
{
    int ch;
    char Name[20];
    top = NULL;

    while (1)
    {
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("1) Push (Insert at the end)\n");
        printf("2) Pop (Delete from the end)\n");
        printf("3) Display Stack\n");
        printf("4) Search by Age\n");
        printf("5) Exit\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter details (Name, Age, Rank):\n");
            scanf("%s%d%d", newnode->name, &newnode->age, &newnode->rank);
            push(newnode);
            break;
        }
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            search_by_age();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

void push(struct node *newnode)
{
    if (top == NULL)
    {
        top = newnode;
        top->next = NULL;
    }
    else
    {
        struct node *temp = top;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
    printf("Node pushed successfully.\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty - Cannot pop.\n");
    }
    else
    {
        if (top->next == NULL)
        {
            printf("Node popped:\nName=%s\tAge=%d\tRank=%d\n", top->name, top->age, top->rank);
            free(top);
            top = NULL;
        }
        else
        {
            struct node *temp = top;
            struct node *prev = NULL;
            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            printf("Node popped:\nName=%s\tAge=%d\tRank=%d\n", temp->name, temp->age, temp->rank);
            free(temp);
            prev->next = NULL;
        }
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        struct node *temp = top;
        printf("Stack Contents:\n");
        while (temp != NULL)
        {
            printf("Name: %s\tAge: %d\tRank: %d\n", temp->name, temp->age, temp->rank);
            temp = temp->next;
        }
    }
}

void search_by_age()
{
    int searchAge;
    printf("Enter the age to search: ");
    scanf("%d", &searchAge);

    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        struct node *temp = top;
        int found = 0;

        printf("Students with age %d:\n", searchAge);
        while (temp != NULL)
        {
            if (temp->age == searchAge)
            {
                printf("Name: %s\tAge: %d\tRank: %d\n", temp->name, temp->age, temp->rank);
                found = 1;
            }
            temp = temp->next;
        }

        if (!found)
        {
            printf("No students found with age %d\n", searchAge);
        }
    }
}
