/*
25. To implement a program to search an element in a singly linked list.

Explanation:
- Start from head with a position counter pos = 1.
- Traverse node by node comparing temp->data with key until temp == NULL.
- Report the 1-based position if found; otherwise report not found.
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
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) {
        printf("Element %d not found in the singly linked list.\n", key);
    }

    return 0;
}

/*
Sample Input:
4
11 22 33 44
33

Sample Output:
Enter number of nodes: Enter value 1: Enter value 2: Enter value 3: Enter value 4: Enter element to search: Element 33 found at position 3.
*/
