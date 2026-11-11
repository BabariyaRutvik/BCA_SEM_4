/*
26. To implement a program to traverse and count the number of nodes in a singly linked list.

Explanation:
- Initialize count = 0 and temp = head.
- Move temp = temp->next while temp != NULL, printing each node's data and
  incrementing count.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *tail = NULL, *newNode, *temp;
    int n, i, val, count = 0;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Traversing Singly Linked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }
    printf("\nTotal number of nodes: %d\n", count);

    return 0;
}

/*
Sample Input:
4
5 15 25 35

Sample Output:
Enter number of nodes to create: Enter value 1: Enter value 2: Enter value 3: Enter value 4: Traversing Singly Linked List: 5 15 25 35 
Total number of nodes: 4
*/
