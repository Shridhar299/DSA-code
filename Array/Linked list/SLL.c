#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

struct node *insert_at_beg();
struct node *insert_at_end();
struct node *insert_at_position(int);
struct node *delete_at_beg();
struct node *delete_at_end();
struct node *delete_at_position(int);
void display();
int count_nodes();
void search_by_age();

int main()
{
    int ch, c, pos;
    head = NULL;

    while (1)
    {
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("1) Insert at beginning\n");
        printf("2) Insert at the end\n");
        printf("3) Insert at specific position\n");
        printf("4) Delete from beginning\n");
        printf("5) Delete from the end\n");
        printf("6) Delete from specific position\n");
        printf("7) Display linked list\n");
        printf("8) Count Nodes\n");
        printf("9) Search by data\n");
        printf("10) Exit\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = insert_at_beg();
            break;
        case 2:
            head = insert_at_end();
            break;
        case 3:
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            head = insert_at_position(pos);
            break;
        case 4:
            head = delete_at_beg();
            break;
        case 5:
            head = delete_at_end();
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            head = delete_at_position(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            c = count_nodes();
            printf("Number of nodes = %d\n", c);
            break;
        case 9:
            search_by_age();
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

struct node *create_node()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

struct node *insert_at_beg()
{
    struct node *newnode = create_node();
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    return head;
}

struct node *insert_at_end()
{
    struct node *newnode = create_node();
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

struct node *insert_at_position(int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return head;
    }

    struct node *newnode = create_node();
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }

    struct node *temp = head;
    int i = 1;

    while (temp != NULL && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Position is greater than the number of nodes\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

void display()
{
    if (head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        struct node *temp = head;
        printf("Data\n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct node *delete_at_beg()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        printf("Node deleted: Data=%d\n", temp->data);
        free(temp);
    }
    return head;
}

struct node *delete_at_end()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if (head->next == NULL)
    {
        printf("Node deleted: Data=%d\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        printf("Node deleted: Data=%d\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
    return head;
}

struct node *delete_at_position(int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1)
    {
        return delete_at_beg();
    }

    struct node *temp = head;
    int i = 1;

    while (temp != NULL && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Position is greater than the number of nodes\n");
        return head;
    }

    struct node *delNode = temp->next;
    temp->next = temp->next->next;

    printf("Node deleted: Data=%d\n", delNode->data);
    free(delNode);

    return head;
}

int count_nodes()
{
    int cnt = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void search_by_age()
{
    int searchData;
    printf("Enter the data to search: ");
    scanf("%d", &searchData);

    if (head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        struct node *temp = head;
        int found = 0;

        printf("Nodes with data %d:\n", searchData);
        while (temp != NULL)
        {
            if (temp->data == searchData)
            {
                printf("Data: %d\n", temp->data);
                found = 1;
            }
            temp = temp->next;
        }

        if (!found)
        {
            printf("No nodes found with data %d\n", searchData);
        }
    }
}

