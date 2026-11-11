/*
35. To implement a program to traverse the doubly linked list in forward and reverse order.

Explanation:
- Forward traversal starts at head and moves via temp = temp->next until NULL.
- Reverse traversal starts at tail (last node) and moves via temp = temp->prev until NULL.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverseForward(struct Node *head) {
    struct Node *temp = head;
    printf("Forward Order: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverseReverse(struct Node *tail) {
    struct Node *temp = tail;
    printf("Reverse Order: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL, *tail = NULL, *newNode;
    int n, i, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->prev = tail;
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    traverseForward(head);
    traverseReverse(tail);

    return 0;
}

/*
Sample Input:
4
5 10 15 20

Sample Output:
Enter number of nodes: Enter value 1: Enter value 2: Enter value 3: Enter value 4: Forward Order: 5 10 15 20 
Reverse Order: 20 15 10 5
*/
