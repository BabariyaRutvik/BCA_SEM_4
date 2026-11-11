/*
22. To implement a program to create a singly linked list and display its elements.

Explanation:
- Each node contains an integer data field and a pointer next to the next node.
- Nodes are dynamically allocated with malloc(). New nodes are linked at the tail
  so the list preserves insertion order, then traversed from head to NULL.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *tail = NULL, *newNode, *temp;
    int n, i, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Singly Linked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

/*
Sample Input:
4
10 20 30 40

Sample Output:
Enter number of nodes: Enter value for node 1: Enter value for node 2: Enter value for node 3: Enter value for node 4: Singly Linked List: 10 -> 20 -> 30 -> 40 -> NULL
*/
