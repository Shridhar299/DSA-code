#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *rl;
    struct node *ll;
};
struct node * create_node();
struct node * insert_end(struct node * head);
struct node * insert_front(struct node * head);
struct node * delete_end(struct node * head);
struct node * delete_front(struct node * head);
struct node * search_delete(struct node * head);
void display(struct node * head);
struct node *cur;
void display_ulta(struct node * head);
int count_a(struct node * head);
void search(struct node * head);

int main()
{
    int ch,count=0;
    struct node *head=NULL;
    while(1)
    {
        printf("\n1.INSERT END\n2.DELETE END\n3.DISPLAY\n4.DISPLAY ulta\n5.COUNT\n6.SEARCH\n7.INSERT FRONT\n8.DELETE FRONT\n9.SEARCH TO DELETE\n10.EXIT\n");
        printf("Enter ur choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=insert_end(head);
            break;
            case 2:head=delete_end(head);
            break;
            case 3:display(head);
            break;
            case 4:display_ulta(head);
            break;
            case 5:count=count_a(head);
            printf("No of list are: %d",count);
            break;
            case 6:search(head);
            break;
            case 10:exit(0);
            break;
            case 9:head=search_delete(head);
            break;
            case 7:head=insert_front(head);
            break;
            case 8:head=delete_front(head);
            break;
            default:printf("Enter valid choice");
        }

    }
}

struct node * create_node()
{
   struct node *newnode;
   newnode=(struct node *)malloc(sizeof(struct node));
   if(newnode==NULL)
   {
       printf("NO memory allocated");
   }
   printf("Enter data\n");
   scanf("%d",&newnode->data);
   newnode->rl=NULL;
   newnode->ll=NULL;
   return newnode;
}
struct node * insert_end(struct node * head)
{
    struct node * newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->rl!=NULL)
        {
            cur=cur->rl;
        }
        newnode->ll=cur;
        cur->rl=newnode;
    }
    return head;
}

struct node * insert_front(struct node * head)
{
    struct node * newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->rl=head;
        head->ll=newnode;
        head=newnode;
    }
    return head;
}

struct node * delete_end(struct node * head)
{
   struct node * prev;
   if(head==NULL)
   {
       printf("LIST EMPTY\n");
   }
   else if(head->rl==NULL)
   {
       printf("deleted %d",head->data);
       free(head);
       head=NULL;
   }
   else
    {
        cur=head;
        while(cur->rl!=NULL)
        {
            cur=cur->rl;
        }
        prev=cur->ll;
        prev->rl=NULL;
        printf("deleted %d",cur->data);
        free(cur);
    }
    return head;
}

struct node * delete_front(struct node * head)
{
    struct node * temp;
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
    }
    else
    {
        temp=head;
        head=head->rl;
        printf("deleted %d",temp->data);
        head->ll=NULL;
        free(temp);
    }
    return head;
}
void display(struct node * head)
{
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->rl;
        }
    }
}

int count_a(struct node * head)
{
    int count=0;
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
    }
    else
    {
        struct node *cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->rl;
        }
    }
    return count;
}

void display_ulta(struct node * head)
{
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
    }
    else
    {
        cur=head;
        while(cur->rl!=NULL)
        {
            cur=cur->rl;
        }
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->ll;
        }
    }
}

void search(struct node * head)
{
    int key,status=0;
    printf("Enter the data to be searched\n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(key==cur->data)
            {
                status=1;
                break;
            }
            cur=cur->rl;
        }
        if(status==0)
        {
            printf("SEARCH unsucessfull\n");
        }
        else if(status==1)
        {
            printf("SEARCH sucessfull\n");
        }
    }
}

struct node * search_delete(struct node * head)
{
    int key,status=0;
    struct node * temp;
    struct node * prev=NULL;
    printf("Enter the data to be deleted\n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("NO DATA TO BE DELETED\n");
    }
    else if(head->data==key)
    {
        head=delete_front(head);
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data==key)
            {
                status=1;
                break;
            }
            prev=cur;
            cur=cur->rl;
        }
        if(status==1)
        {
            prev->rl=cur->rl;
            printf("Deleted %d",key);
            free(cur);
        }
    }
    return head;
}
