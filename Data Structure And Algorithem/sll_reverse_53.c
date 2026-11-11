/*
53. To implement a program to reverse a singly linked list.

Explanation:
- Uses three pointers: prev (initially NULL), current (initially head), and next.
- In each step, save next = current->next, reverse current->next = prev,
  then advance prev = current and current = next.
- Finally update head = prev. Runs in O(n) time and O(1) extra space.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node *reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *nextNode = NULL;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
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
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Original List: ");
    display(head);

    head = reverseList(head);

    printf("Reversed List: ");
    display(head);

    return 0;
}

/*
Sample Input:
4
10 20 30 40

Sample Output:
Enter number of nodes: Enter value 1: Enter value 2: Enter value 3: Enter value 4: Original List: 10 -> 20 -> 30 -> 40 -> NULL
Reversed List: 40 -> 30 -> 20 -> 10 -> NULL
*/
