#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

struct node *insert_at_beg(struct node *);
struct node *insert_at_end(struct node *);
struct node *insert_at_position(struct node *, int);
struct node *delete_at_beg(struct node *);
struct node *delete_at_end(struct node *);
struct node *delete_at_position(struct node *, int);
void display(struct node *);
int count_nodes(struct node *);
void search_by_value(struct node *);

int main()
{
    int ch, pos;
    head = NULL;

    while (1)
    {
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("1) insert at beginning\n");
        printf("2) insert at the end\n");
        printf("3) insert at specific position\n");
        printf("4) delete from beginning\n");
        printf("5) delete from the end\n");
        printf("6) delete from specific position\n");
        printf("7) display linked list\n");
        printf("8) Count Nodes\n");
        printf("9) searching by data\n");
        printf("10) exit\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = insert_at_beg(head);
            break;
        case 2:
            head = insert_at_end(head);
            break;
        case 3:
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            head = insert_at_position(head, pos);
            break;
        case 4:
            head = delete_at_beg(head);
            break;
        case 5:
            head = delete_at_end(head);
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            head = delete_at_position(head, pos);
            break;
        case 7:
            display(head);
            break;
        case 8:
            printf("Number of nodes = %d\n", count_nodes(head));
            break;
        case 9:
            search_by_value(head);
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
    if (!newnode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

struct node *insert_at_beg(struct node *head)
{
    struct node *newnode = create_node();
    if (head == NULL)
    {
        head = newnode;
        head->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        head = newnode;
        temp->next = head;
    }
    return head;
}

struct node *insert_at_end(struct node *head)
{
    struct node *newnode = create_node();
    if (head == NULL)
    {
        head = newnode;
        head->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    return head;
}

struct node *insert_at_position(struct node *head, int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return head;
    }

    struct node *newnode = create_node();

    if (pos == 1)
    {
        return insert_at_beg(head);
    }

    struct node *temp = head;
    int i = 1;

    while (temp->next != head && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp->next == head && i < pos - 1)
    {
        printf("Position is greater than the number of nodes\n");
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        struct node *temp = head;
        printf("Data\n");
        do
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

struct node *delete_at_beg(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return head;
    }

    struct node *temp = head;
    if (head->next == head)
    {
        printf("Node deleted: Data=%d\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        struct node *toDelete = head;
        head = head->next;
        temp->next = head;
        printf("Node deleted: Data=%d\n", toDelete->data);
        free(toDelete);
    }
    return head;
}

struct node *delete_at_end(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return head;
    }

    struct node *temp = head, *prev = NULL;
    if (head->next == head)
    {
        printf("Node deleted: Data=%d\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        printf("Node deleted: Data=%d\n", temp->data);
        prev->next = head;
        free(temp);
    }
    return head;
}

struct node *delete_at_position(struct node *head, int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1)
    {
        return delete_at_beg(head);
    }

    struct node *temp = head;
    int i = 1;

    while (temp->next != head && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp->next == head || temp->next == NULL)
    {
        printf("Position is greater than the number of nodes\n");
        return head;
    }

    struct node *toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Node deleted: Data=%d\n", toDelete->data);
    free(toDelete);

    return head;
}

int count_nodes(struct node *head)
{
    int cnt = 0;
    if (head == NULL)
    {
        return cnt;
    }
    else
    {
        struct node *temp = head;
        do
        {
            cnt++;
            temp = temp->next;
        } while (temp != head);
        return cnt;
    }
}

void search_by_value(struct node *head)
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
        do
        {
            if (temp->data == searchData)
            {
                printf("Data: %d\n", temp->data);
                found = 1;
            }
            temp = temp->next;
        } while (temp != head);

        if (!found)
        {
            printf("No nodes found with data %d\n", searchData);
        }
    }
}