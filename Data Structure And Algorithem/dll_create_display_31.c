/*
31. To implement a program to create a doubly linked list and display its elements in both directions.

Explanation:
- Each node in a Doubly Linked List (DLL) has data, a prev pointer, and a next pointer.
- Forward display follows next pointers from head to tail.
- Backward display follows prev pointers from tail back to head.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *tail = NULL, *newNode, *temp;
    int n, i, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("Forward Direction: ");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Backward Direction: ");
    temp = tail;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");

    return 0;
}

/*
Sample Input:
4
10 20 30 40

Sample Output:
Enter number of nodes: Enter value 1: Enter value 2: Enter value 3: Enter value 4: Forward Direction: 10 <-> 20 <-> 30 <-> 40 <-> NULL
Backward Direction: 40 <-> 30 <-> 20 <-> 10 <-> NULL
*/
