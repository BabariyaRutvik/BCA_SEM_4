/*
30. To implement a program to search an element in a circular linked list.

Explanation:
- Start from head with pos = 1 and loop using do-while until temp returns to head.
- If temp->data == key, report the position and stop; otherwise report not found.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *tail = NULL, *newNode, *temp;
    int n, i, val, key, pos = 1, found = 0;

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

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (head != NULL) {
        temp = head;
        do {
            if (temp->data == key) {
                printf("Element %d found at position %d.\n", key, pos);
                found = 1;
                break;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
    }

    if (!found) {
        printf("Element %d not found in the circular linked list.\n", key);
    }

    return 0;
}

/*
Sample Input:
4
15 25 35 45
35

Sample Output:
Enter number of nodes: Enter value 1: Enter value 2: Enter value 3: Enter value 4: Enter element to search: Element 35 found at position 3.
*/
