/*
27. To implement a program to create a circular linked list and display its elements.

Explanation:
- In a Circular Linked List (CLL), the last node's next pointer points back to head
  instead of NULL.
- Traversal uses a do-while loop starting at head until temp returns to head.
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
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        if (head == NULL) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
    } else {
        printf("Circular Linked List: ");
        temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(back to head %d)\n", head->data);
    }

    return 0;
}

/*
Sample Input:
4
10 20 30 40

Sample Output:
Enter number of nodes: Enter value 1: Enter value 2: Enter value 3: Enter value 4: Circular Linked List: 10 -> 20 -> 30 -> 40 -> (back to head 10)
*/
