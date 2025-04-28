// C program to find the data at nth node
// recursively

#include <stdio.h>
struct Node {
    int data;
    struct Node *next;
};

// Takes head pointer of the linked list and index
// as arguments and returns data at index.
int GetNth(struct Node *head, int index) {
  
    // If the list is empty or index is out of bounds
    if (head == NULL)
        return -1;

    // If index equals 1, return node's data
    if (index == 1)
        return head->data;

    // Recursively move to the next node
    return GetNth(head->next, index - 1);
}

struct Node *createNode(int new_data) {
    struct Node *new_node =
      (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int count(struct Node *head){
	int cnt=0;
	struct Node *temp=head;
	while(temp!=NULL){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}

int main() {
  
    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    int num=scanf("%d",&num);
    int num1=(count(head)) - num + 1;
    printf("%d\n", GetNth(head, num1));

    return 0;
}
